#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

#define TAM_LI 20
#define TAM_LP 20
#define TAM_NOME 20

typedef struct
{
    //VidaTot é a vida total do jogador que irá aumentar com o nível enquanto vida é aquela que muda constantemente
    int vida, dano, def, vidaTot, dif;
    char nome[TAM_NOME];
} personagem;

typedef struct
{
    int vida, dano, def, vidaTot;
} inimigo;


void limparTela()
{
    printf("\n\nPressione Enter para continuar...");
    fflush(stdin);
    getchar();
    system("cls");
}

void asciiMenu()
{

    printf(" #######                                             ######                                                             ");
    printf(" #        #  #####   ######       ####   ######      #     #  ######  #####   ######  #       #       #   ####   #    # ");
    printf(" #        #  #    #  #           #    #  #           #     #  #       #    #  #       #       #       #  #    #  ##   # ");
    printf(" #####    #  #    #  #####       #    #  #####       ######   #####   #####   #####   #       #       #  #    #  # #  # ");
    printf(" #        #  #####   #           #    #  #           #   #    #       #    #  #       #       #       #  #    #  #  # # ");
    printf(" #        #  #   #   #           #    #  #           #    #   #       #    #  #       #       #       #  #    #  #   ## ");
    printf(" #        #  #    #  ######       ####   #           #     #  ######  #####   ######  ######  ######  #   ####   #    # \n\n");
    printf("Para aumentar ou diminuir o jogo, pressione Ctrl + Scroll do Mouse\n\n");
}

void asciiWin()
{

    printf("Agora, peço a você Herói, que imagine uma música épica. Na realidade, abra uma música aí e sinta a emoção deste momento.\nAfinal, o Héroi de nossa história finalmente salvou a Princesa e com isso o fim chegou... \nAmores de infância, o Herói e a Princesa se reencontraram e não havia mais nenhum impeditivo. \nMas você deve estar se perguntando, onde estava O TERROR DE TODOS, DESPRESÍVEL, MALFEITOR, BÁRBARO, PERVERSO, FACÍNORA, DEGENERADO, CRUEL, VIL e IMPIEDOSO Vilão de nossa história... Bem o Rei Demônio estava em outro castelo... \n\nEu não acredito, que eu acabei de referenciar a Nintendo em um jogo. Essa profissão de Narrador é \nsimplesmente a melhor de todas! Bom jogador, meus parabéns e se você conhecer um programador de jogos, fala para ele \nme contratar, por favor! Tá faltando uns 'jobs' de Narrador e normalmente o pessoal só imagina a minha voz... \n\n");
    printf("                                                                                          (\\/)\n");
    printf("                                                                                           \\/\n");
    printf("                                                                                     (,);\n");
    printf("                                                                                    ((  ^_.  ...\n");
    printf("                                                                                     ' / /_\\(()))\n");
    printf("                                                                                       L( '}{' ())\n");
    printf("                                                                                       ) (   )_ (()\n");
    printf("                                                                                     (_   \ (   (_)\n");
    printf("                                                                                     | (__'__\_) |\n");
    printf("                                                                                      \\___|_(}==/ \\\n");
    printf("                                                                                      |    |  |    |\n");
    printf("                                                                                       |_/\_|  |    |\n");
    printf("                                                                                       |  |   |    |\n");
    printf("                                                                                        ) )\\  |    |\n");
    printf("                                                                                      _/| |/  |    \\\n");
    printf("                                                                                     ( ,\\ |_  '~~~~/7\n");
    printf("                                                                                      \\_(___)  _/Y\n\n\n");
    printf("                                                         UM JOGO DE NICOLAS GABRIEL E ROSA DE SOUZA\n\n");

}

//Criador de inimigo
const char* listInim()
{

    const char* listI[TAM_LI] =
    {
        "Cobra coral",
        "Aranha-Laranja",
        "Escorpião-Príncipe",
        "Enxame de abelhas",
        "Marimbondo gigante",
        "Taturana de fogo",
        "Lacraia centípede",
        "Vespa elétrica",
        "Morcego das trevas",
        "Barata colossal",
        "Slime geléco",
        "Zumbi desmiolado",
        "Cogumelo irritante",
        "Tartaruga velocista",
        "Esqueleto Snas",
        "Cachorro Uaua",
        "Dragão bebê",
        "Criatura 'Narrador está sem nenhuma criatividade'",
        "Macaco guerreiro",
        "Seu-menor pesadelo"
    };

    const char* inimRand;

    inimRand = listI[rand() % TAM_LI];

    return inimRand;

}

void statInim(inimigo *i)
{

    //Inimigo
    i->vidaTot = rand() % 50 + 50;
    i->vida = i->vidaTot;
    //O 3 é o valor minimo, para o inimigo não mandar ataques negativos
    i->dano = rand() % 10 + 5;
    i->def = rand() % 5;

}

//Lista com todas piadinhas
const char* listPiadas()
{

    const char* listP[TAM_LP] =
    {
        "Você entregou flores ao seu inimigo.",
        "Você deu uma nota de R$100,00 ao inimigo.",
        "O inimigo fez uma piada por você estar jogando um jogo chamado Fire of Rebellion.",
        "Você passou uma cantada a seu inimigo.",
        "WOULD YOU KINDLY nunca mais escolher estas três interrogações “???”",
        "Sabe, a vida é bem solitária por aqui como um narrador, então tenho muito tempo para pensar. Uma coisa que fica me incomodando é esse conceito de felicidade. Todo mundo parece estar buscando ela, alguns fingem que a tem, mas ninguém consegue mesmo explicá-la. Eu acho que finalmente desvendei o mistério. Sabe, todo mundo tem objetivos. Então a gente pensa... ah, quando eu tiver isso, serei feliz, ou, quando eu conseguir aquilo, terei alegria eterna. Algumas pessoas estão buscando amor e aceitação, enquanto outros simplesmente esperam que a Devolver aprove seu jogaço. Do meu ponto de vista, sentado aqui às margens do tempo e sendo visitado por inúmeros viajantes, percebi uma coisa muito importante. Objetivos não deixam ninguém feliz. Eles adiam a felicidade para o futuro, para quando o objetivo será alcançado. Isso só leva ao fracasso, pois quando atingir o objetivo, você não será mais a mesma pessoa que era quando decidiu buscá-lo. E além disso, sua mente estará programada para buscar alguma coisa em vez de simplesmente desfrutar daquilo que já tem. Então é isso. A felicidade não é um objetivo ou um estado, é um sistema. Você otimiza seu ambiente e escolhe a dedo as pessoas ao seu redor. De forma que a cada dia você esteja animado para viver sua vida, e você não precisa adiar nenhuma alegria, pois você já otimizou o momento presente. Agora não sei se isso foi cafona ou inspirador, ou talvez até irritante, mas eu preciso otimizar minha própria vida. E isso significa que preciso que você pare de tentar sempre a sorte, então espero ter entediado você pra valer.",
        "Você fez um trocadilho com o nome do seu inimigo e ele começou a chorar.",
        "No fim, a vida é uma grande caixinha de surpresas.",
        "Objection! Calma lá Herói, peguei o roteiro errado...",
        "Você abraçou seu inimigo, com muito amor.",
        "A melhor solução para um problema é geralmente a mais fácil...",
        "Todas as pessoas que eu gostava morreram ou me deixaram Herói… Todo mundo menos você! Então por favor, jogue com sabedoria",
        "It's a me... Narrator",
        "Tem uma história, de um outro Herói chamado Zeldo... Tô pensando seriamente em ir narrar a dele e deixar essa história de lado",
        "Você começou a contar a seu inimigo suas maiores façanhas e ele dormiu no meio.",
        "Você ofereceu uma maçã ao seu inimigo.",
        "Toma aqui, parabéns, achou que o jogo ficou mais fácil agora?",
        "Você jogou um tijolo na cabeça do seu inimigo (PARA QUE TANTA AGRESSIVIDADE? CALMA HERÓI, É SÓ UM JOGO POW)",
        "Sabe aquela cena fofa de E.T. O Extraterrestre? Você tentou recriá-la",
        "Tudo bem. Aqui vão alguns pensamentos de Jordan, o Sábio, para você. A vida é dura, então tem algumas coisas que você deveria saber. O mais importante de tudo é perceber que você tem alguma coisa para oferecer ao mundo. Mas para conseguir fazer isso, antes você precisa se conhecer e se organizar. Dar ouvidos às lições contidas nas histórias dos antigos não é uma má ideia. Sabe, com o aumento de conhecimento da consciência humana, sua arrogância também aumentou. Parece que estamos em um ponto em que o valor das histórias se perdeu para todos. Sem se importar com lições de moral, estamos simplesmente buscando diversão. Mas o poder delas no nosso subconsciente não se deixa afetar pelo nosso orgulho intelectual. As histórias enviam uma mensagem clara para o nosso ser, e quando são bem contadas, podem indicar caminhos para vivermos nossas vidas, às vezes impactando de maneiras que nem ao menos percebemos. Na verdade, os temas recorrentes quase sempre representam arquétipos, e contêm lições sobre como devemos ou não devemos nos portar. Pegue os dragões, por exemplo. As histórias de fantasia quase sempre os retratam com montes de tesouros. Não por coincidência, dois dos maiores medos inatos dos mamíferos são o fogo e os répteis. Então os dragões na verdade são uma metáfora que representa aquilo que você mais teme. Mas, diga, por que um réptil imortal cuspidor de fogo ia querer dormir em uma pilha de ouro? A resposta está nas entrelinhas: o tesouro que você busca é protegido pelo seu maior medo. Não me entenda mal, a pilha de ouro também é só uma metáfora, assim como a grandiosa besta que nem sequer existe. Encontre o seu dragão e derrote-o, aí então o seu tesouro será revelado. Esse é o conhecimento que os antigos contadores de histórias queriam transmitir, só que eles não tinham o método científico, nem um modelo para estruturar seus argumentos, e nem sequer uma audiência com QI elevado. Nem por isso a lição é menos importante hoje em dia. Aquilo que você realmente precisa descobrir dentro de si está escondido onde você menos quer buscar. Pergunte a si mesmo: por que você estava tão curioso para abrir o armário? Por acaso você é uma pessoa muito escrupulosa, inexoravelmente olhando sob cada pedra que passa? Ou será que você não dominou suas inseguranças, e o medo de perder alguma coisa é o que te move nesse momento? Talvez você esteja simplesmente querendo rir de alguma fala inesperada? Pois vou admitir que eu poderia arruinar todo o clima agora e contar a você sobre o palhaço depressivo que tentou se animar comendo um prato de confete. O que eu quero dizer é que, independente do motivo que o trouxe até aqui, você claramente demonstrou curiosidade, e fé de que o mundo guarda surpresas para aqueles dispostos a dar uma olhada sincera. Apesar de isso certamente ser verdade sobre o mundo, é ainda mais verdade sobre seu eu interior. Agora, se isso é assustador, inspirador ou encorajador, depende totalmente de quão longe você chegou em sua jornada de crescimento pessoal. A vida é feita de várias provas, e a maioria delas vai aparecer para você mais de uma vez. Traição, alegria, doença, aventura, falsidade, cooperação, intenção, solidão, gentileza, lealdade... De fato, assim como as velhas e as novas histórias, a vida tem temas recorrentes para testar os humanos. A parte importante não é saber se você passou ou não no teste, mas comparecer, ver seu resultado e ponderar sobre como isso pode mostrar o ser que você deve se tornar. A partir disso, tudo está dentro de você para ajudá-lo a encontrar seu próprio caminho. Vai saber, talvez o sentido principal da história do Herói possa até fazer sentido para você. Mas, por ora, vamos voltar para a sua aventura."
    };

    const char* piadRand;

    piadRand = listP[rand() % TAM_LP];

    return piadRand;

}

void filecg(char *nome, int dif, int qPoc, int turno)
{

    FILE *arq;

    // Gravando no arquivo
    arq = fopen("save.sv", "ab");

    if(arq == NULL)
    {
        printf("\nNão foi possível abrir o arquivo.");
    }
    else
    {
        //Nome do jogador
        fprintf(arq, "Nome do jogador: %s\n", nome);

        //Checando se selecionou uma dificuldade normal
        if(dif != 0)
        {
            fprintf(arq, "Dificuldade: %d\n", dif);
        }
        else
        {
            fprintf(arq, "Modo Difícil!!!!\n");
        }

        fprintf(arq, "Quantidade de poções: %d\n", qPoc);

        //Checa se venceu ou não
        if(turno <= 10)
        {
            fprintf(arq, "Chegou a turno: %d\n\n", turno);
        }
        else
        {
            fprintf(arq, "Venceu!\n\n");
        }

        fclose(arq);
    }
}

//Menu de batalha
int batalha(personagem *x, inimigo *y, int dif)
{
    //Nome do inimigo
    const char* iNome;
    iNome = listInim();

    //Randomiza o primeiro inimigo
    statInim(y);

    //Turnos
    int turno = 0;

    //Valor para selecionar opção
    int op;

    //Ataques criticos
    srand( (unsigned)time(NULL) );
    int crit;

    //Variavel de ataque personagem/ataque inimigo
    int ata, ataen;

    //Resto da vida
    int remain;

    //Quantidade poções
    int qPoc;

    //Chance de ??? acertar/conseguir correr
    int certo, correr;

    //Quantidade de poções por dificuldade
    switch(dif)
    {
        case 1:
            qPoc = 10;
            break;
        case 2:
            qPoc = 6;
            break;
        case 3:
            qPoc = 3;
            break;
        default:
            printf("----- Você escolheu o modo impossível! (0 poções) -----\n\n\n");
            dif = 0;
            qPoc = 0;
            break;
    }

    while(turno < 10)
    {

        //Randomiza valor do critico
        crit = rand() % 10;

        printf("Turno [%d/10]\n", turno+1);

        //Escolha de ação
        printf("Selecione sua ação: \n \n1 - Atacar \n2 - Cura \n3 - ??? \n4 - Correr\n");

        //Printa vida do personagem
        printf("\n%s HP: %d/%d\n", x->nome,x->vida, x->vidaTot);
        //Printa vida do inimigo
        printf("%s HP: %d/%d\n>> ", iNome,y->vida, y->vidaTot);

        scanf("%d", &op);


        switch(op)
        {

        //Atacar
        case 1:

            //Ataque personagem sem ???
            ata = (x->dano + crit) - (y->def/2);

            //Tira vida do inimigo
            printf("\n(%s deu %d de dano.)\n", x->nome, ata);
            y->vida -= ata;

            break;

        //Cura
        case 2:

            //O resto da conta
            remain = x->vidaTot - x->vida;


            if(qPoc > 0)
            {
                //Tira uma poção do inventário
                qPoc--;

                //Se vida estiver igual a vida total (tem que adicionar um if ao cima de tudo para ver se tem poção)
                if(x->vida == x->vidaTot)
                {
                    printf("\nSua vida está cheia!\n\n");
                    qPoc++;

                }

                //Quando usar a poção elá iria encher 20 (pode mudar para qualquer valor),
                //entretanto como ia ser maior que a vida total então é melhor utilizar o resto de vida que tinha
                else if(x->vida >= (x->vidaTot - 20))
                {
                    x->vida += remain;
                    printf("\nVocê recuperou %d de vida! Sua vida está cheia!\n", remain);
                    printf("\nVocê tem %d poções no momento\n", qPoc);

                }
                //Recupera 20 de vida
                else
                {
                    x->vida += 20;
                    printf("\nVoce recuperou 20 de vida!\nSua vida: %d/%d\n", x->vida, x->vidaTot);
                    printf("\nVocê tem %d poções no momento\n", qPoc);

                }


            }
            else
            {
                printf("\nVocê está sem poções!\n");
            }

            break;

        //???
        case 3:

            //1/3 de chance de acertar
            certo = rand() % 3;

            printf("\n%s\n", listPiadas());

            //Ação deu certo
            if(certo == 1)
            {
                y->def = 0;
                printf("%s ficou confuso! Defesa do inimigo abaixou\n", iNome);
            }

            //Falhou
            else
            {
                printf("...Nada aconteceu\n");
            }

            break;

        //Correr
        case 4:

            // Chance de 50% (Pode alterar)
            correr = rand() % 2;

            //Corre (no momento só vai para o menu principal)
            if(correr == 1)
            {
                printf("\nVoce conseguiu correr do inimigo! O que não sabia, é que nessa história não há lugar aos fracos.");
                filecg(x->nome, dif, qPoc, turno+1);
                limparTela();
                return 1;
            }

            //Falhou
            else
            {
                printf("\nVocê não conseguiu correr\n");
            }

            break;

        default:
            printf("Opção inválida!!!\n");
            limparTela();
        }


        //Ataque inimigo
        ataen = (y->dano + crit) - (x->def/10);

        //Inimigo deu x de dano
        printf("\n(%s deu %d de dano.)\n", iNome, ataen);
        x->vida -= ataen;

        //Limpa a tela
        limparTela();

        //Game over
        if(x->vida <= 0)
        {
            printf("Bem, o Herói não era um dos mais capazes do reino... Ele se juntou a mim lutando contra um simples lacaio do Rei Demônio\n");
            printf("               ...\n");
            printf("             ;::::;\n");
            printf("           ;::::; :;\n");
            printf("           ;::::; :;\n");
            printf("         ;:::::'   :;\n");
            printf("        ;:::::;     ;.\n");
            printf("       ,:::::'       ;           OOO\\\n");
            printf("       ::::::;       ;          OOOOO\\\n");
            printf("       ;:::::;       ;         OOOOOOOO\n");
            printf("      ,;::::::;     ;'         / OOOOOOO\n");
            printf("    ;:::::::::`. ,,,;.        /  / DOOOOOO\n");
            printf("  .';:::::::::::::::::;,     /  /     DOOOO\n");
            printf(" ,::::::;::::::;;;;::::;,   /  /        DOOO\n");
            printf(";`::::::`'::::::;;;::::: ,#/  /          DOOO\n");
            printf(":`:::::::`;::::::;;::: ;::#  /            DOOO\n");
            printf("::`:::::::`;:::::::: ;::::# /              DOO\n");
            printf("`:`:::::::`;:::::: ;::::::#/               DOO\n");
            printf(" :::`:::::::`;; ;:::::::::##                OO\n");
            printf(" ::::`:::::::`;::::::::;:::#                OO\n");
            printf(" `:::::`::::::::::::;'`:;::#                O\n");
            printf("  `:::::`::::::::;' /  / `:#\n");
            printf("   ::::::`:::::;'  /  /   `#");
            limparTela();
            filecg(x->nome, dif, qPoc, turno+1);
            return 1;
        }

        //Tela de parabéns
        if(y->vida <= 0)
        {
            printf("Você derrotou %s!\nHP atual: %d/%d\n", iNome, x->vida, x->vidaTot);

            limparTela();

            //Volta vida do inimigo e randomiza os stats
            y->vida = y->vidaTot;
            statInim(y);
            turno++;
            iNome = listInim();
        }
    }

    filecg(x->nome, dif, qPoc, turno+1);
    asciiWin();
    limparTela();
    return 1;

}


int menu()
{
    int dif;
    personagem pe;
    inimigo ce;

    int opcao;
    char yesno;

    asciiMenu();
    printf("\n1) Começar a Aventura");
    printf("\n2) Desistir da Aventura");

    printf("\n\nEscolha a opção desejada: ");
    scanf("%d", &opcao);

    switch(opcao)
    {

    case 1:

        //Cria nome do personagem
        system("cls");
        printf("      _,.\n");
        printf("    ,` -.)\n");
        printf("   ( _/-\\-._\n");
        printf("  /,|`--._,-^|            ,\n");
        printf("   \_| |`-._/||          ,'|\n");
        printf("    |  `-, / |         /  /\n");
        printf("    |     || |        /  /\n");
        printf("     `r-._||/   __   /  /\n");
        printf(" __,-<_     )`-/  `./  /\n");
        printf("  '  \   `---'   \   /  /\n");
        printf("    |           |./  /\n");
        printf("    /           //  /\n");
        printf("  \_/' \         |/  /\n\n");
        printf("Escreva o nome do seu personagem: ");
        fflush(stdin);
        scanf("%s", pe.nome);
        fflush(stdin);

        //Personagem
        pe.vidaTot = 200;
        pe.vida = pe.vidaTot;
        pe.dano = 30;
        pe.def = 50;

        //Escolha de dificuldade
        system("cls");
        printf("Escolha sua dificuldade: \n \n1 - Fácil\n2 - Normal\n3 - Díficil\n>> ");
        scanf("%d", &dif);

        pe.dif = dif;

        //Narrador
        system("cls");
        printf("De todas as histórias contadas pelos nossos antepassados, nenhuma se compara a de %s.\nO único que conseguiu salvar a Princesa das garras do temível, Rei Demônio, em uma aventura anterior.\nA nossa história começa na entrada do castelo, onde %s tomou uma decisão crucial.", pe.nome, pe.nome);
        limparTela();

        //Parte 1
        printf("Você deseja mesmo abrir o portão? (s/n)\n(Escreve p nessa seção se quiser pular o diálogo)\n>> ");
        fflush(stdin);
        scanf("%s", &yesno);
        system("cls");

        if(yesno == 'p' || yesno == 'P')
        {
            //Começa batalha
            system("cls");
            batalha(&pe, &ce, pe.dif);
            break;
        }
        // Parte 2
        else if(yesno == 's' || yesno == 'S')
        {
            yesno = ' ';
            printf("Deseja mesmo, realmente abrir este portão? (s/n)\n>> ");
            scanf("%s", &yesno);

            //Parte 3
            if(yesno == 's' || yesno == 'S')
            {
                system("cls");
                yesno = ' ';
                printf("É A ÚLTIMA VEZ QUE EU PERGUNTO, ACREDITE EM MIM, VOCÊ SOFRERÁ E PODE NUNCA MAIS VOLTAR.\nTROCARIA SUA VIDA PARA SALVAR UMA PRINCESA QUE NEM SABEMOS SE ESTÁ MESMO NESSE CASTELO? (s/n)\n>> ");
                scanf("%s", &yesno);

                //Começa batalha
                if(yesno == 's' || yesno == 'S')
                {
                    system("cls");
                    batalha(&pe, &ce, pe.dif);
                    break;
                }
                //Parte 3
                else
                {
                    system("cls");
                    printf("Meu Deus, %s... Chegou até aqui e desistiu assim...", pe.nome);
                }
            }
            //Parte 2
            else
            {
                system("cls");
                printf("E por mais que a coragem, permeou %s, esse sempre foi um fraco...", pe.nome);
            }
        }
        //Parte 1
        else
        {
            system("cls");
            printf("Mas essa história, por mais heroica que seja, não foi protagonizada por %s.\nNa realidade, esse se acovardou e desistiu de tudo… Desde todas as riquezas que o esperavam, até o seu grande amor.", pe.nome);
        }

    case 2:
        printf("\n\nCara, você nem se esforçou um pouquinho... FIM DE JOGO!!!\n");
        limparTela();
        return 0;
    default:
        printf("\n\nAcho que esse jogador não é o Herói não. Ele não conseguiu nem digitar o comando correto!!!");
        limparTela();
    }

    return 1;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    system("color 0A");

    while(menu())
    {
        system("cls");
    }

    return 0;
}
