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
    //VidaTot � a vida total do jogador que ir� aumentar com o n�vel enquanto vida � aquela que muda constantemente
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

    printf("Agora, pe�o a voc� Her�i, que imagine uma m�sica �pica. Na realidade, abra uma m�sica a� e sinta a emo��o deste momento.\nAfinal, o H�roi de nossa hist�ria finalmente salvou a Princesa e com isso o fim chegou... \nAmores de inf�ncia, o Her�i e a Princesa se reencontraram e n�o havia mais nenhum impeditivo. \nMas voc� deve estar se perguntando, onde estava O TERROR DE TODOS, DESPRES�VEL, MALFEITOR, B�RBARO, PERVERSO, FAC�NORA, DEGENERADO, CRUEL, VIL e IMPIEDOSO Vil�o de nossa hist�ria... Bem o Rei Dem�nio estava em outro castelo... \n\nEu n�o acredito, que eu acabei de referenciar a Nintendo em um jogo. Essa profiss�o de Narrador � \nsimplesmente a melhor de todas! Bom jogador, meus parab�ns e se voc� conhecer um programador de jogos, fala para ele \nme contratar, por favor! T� faltando uns 'jobs' de Narrador e normalmente o pessoal s� imagina a minha voz... \n\n");
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
        "Escorpi�o-Pr�ncipe",
        "Enxame de abelhas",
        "Marimbondo gigante",
        "Taturana de fogo",
        "Lacraia cent�pede",
        "Vespa el�trica",
        "Morcego das trevas",
        "Barata colossal",
        "Slime gel�co",
        "Zumbi desmiolado",
        "Cogumelo irritante",
        "Tartaruga velocista",
        "Esqueleto Snas",
        "Cachorro Uaua",
        "Drag�o beb�",
        "Criatura 'Narrador est� sem nenhuma criatividade'",
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
    //O 3 � o valor minimo, para o inimigo n�o mandar ataques negativos
    i->dano = rand() % 10 + 5;
    i->def = rand() % 5;

}

//Lista com todas piadinhas
const char* listPiadas()
{

    const char* listP[TAM_LP] =
    {
        "Voc� entregou flores ao seu inimigo.",
        "Voc� deu uma nota de R$100,00 ao inimigo.",
        "O inimigo fez uma piada por voc� estar jogando um jogo chamado Fire of Rebellion.",
        "Voc� passou uma cantada a seu inimigo.",
        "WOULD YOU KINDLY nunca mais escolher estas tr�s interroga��es �???�",
        "Sabe, a vida � bem solit�ria por aqui como um narrador, ent�o tenho muito tempo para pensar. Uma coisa que fica me incomodando � esse conceito de felicidade. Todo mundo parece estar buscando ela, alguns fingem que a tem, mas ningu�m consegue mesmo explic�-la. Eu acho que finalmente desvendei o mist�rio. Sabe, todo mundo tem objetivos. Ent�o a gente pensa... ah, quando eu tiver isso, serei feliz, ou, quando eu conseguir aquilo, terei alegria eterna. Algumas pessoas est�o buscando amor e aceita��o, enquanto outros simplesmente esperam que a Devolver aprove seu joga�o. Do meu ponto de vista, sentado aqui �s margens do tempo e sendo visitado por in�meros viajantes, percebi uma coisa muito importante. Objetivos n�o deixam ningu�m feliz. Eles adiam a felicidade para o futuro, para quando o objetivo ser� alcan�ado. Isso s� leva ao fracasso, pois quando atingir o objetivo, voc� n�o ser� mais a mesma pessoa que era quando decidiu busc�-lo. E al�m disso, sua mente estar� programada para buscar alguma coisa em vez de simplesmente desfrutar daquilo que j� tem. Ent�o � isso. A felicidade n�o � um objetivo ou um estado, � um sistema. Voc� otimiza seu ambiente e escolhe a dedo as pessoas ao seu redor. De forma que a cada dia voc� esteja animado para viver sua vida, e voc� n�o precisa adiar nenhuma alegria, pois voc� j� otimizou o momento presente. Agora n�o sei se isso foi cafona ou inspirador, ou talvez at� irritante, mas eu preciso otimizar minha pr�pria vida. E isso significa que preciso que voc� pare de tentar sempre a sorte, ent�o espero ter entediado voc� pra valer.",
        "Voc� fez um trocadilho com o nome do seu inimigo e ele come�ou a chorar.",
        "No fim, a vida � uma grande caixinha de surpresas.",
        "Objection! Calma l� Her�i, peguei o roteiro errado...",
        "Voc� abra�ou seu inimigo, com muito amor.",
        "A melhor solu��o para um problema � geralmente a mais f�cil...",
        "Todas as pessoas que eu gostava morreram ou me deixaram Her�i� Todo mundo menos voc�! Ent�o por favor, jogue com sabedoria",
        "It's a me... Narrator",
        "Tem uma hist�ria, de um outro Her�i chamado Zeldo... T� pensando seriamente em ir narrar a dele e deixar essa hist�ria de lado",
        "Voc� come�ou a contar a seu inimigo suas maiores fa�anhas e ele dormiu no meio.",
        "Voc� ofereceu uma ma�� ao seu inimigo.",
        "Toma aqui, parab�ns, achou que o jogo ficou mais f�cil agora?",
        "Voc� jogou um tijolo na cabe�a do seu inimigo (PARA QUE TANTA AGRESSIVIDADE? CALMA HER�I, � S� UM JOGO POW)",
        "Sabe aquela cena fofa de E.T. O Extraterrestre? Voc� tentou recri�-la",
        "Tudo bem. Aqui v�o alguns pensamentos de Jordan, o S�bio, para voc�. A vida � dura, ent�o tem algumas coisas que voc� deveria saber. O mais importante de tudo � perceber que voc� tem alguma coisa para oferecer ao mundo. Mas para conseguir fazer isso, antes voc� precisa se conhecer e se organizar. Dar ouvidos �s li��es contidas nas hist�rias dos antigos n�o � uma m� ideia. Sabe, com o aumento de conhecimento da consci�ncia humana, sua arrog�ncia tamb�m aumentou. Parece que estamos em um ponto em que o valor das hist�rias se perdeu para todos. Sem se importar com li��es de moral, estamos simplesmente buscando divers�o. Mas o poder delas no nosso subconsciente n�o se deixa afetar pelo nosso orgulho intelectual. As hist�rias enviam uma mensagem clara para o nosso ser, e quando s�o bem contadas, podem indicar caminhos para vivermos nossas vidas, �s vezes impactando de maneiras que nem ao menos percebemos. Na verdade, os temas recorrentes quase sempre representam arqu�tipos, e cont�m li��es sobre como devemos ou n�o devemos nos portar. Pegue os drag�es, por exemplo. As hist�rias de fantasia quase sempre os retratam com montes de tesouros. N�o por coincid�ncia, dois dos maiores medos inatos dos mam�feros s�o o fogo e os r�pteis. Ent�o os drag�es na verdade s�o uma met�fora que representa aquilo que voc� mais teme. Mas, diga, por que um r�ptil imortal cuspidor de fogo ia querer dormir em uma pilha de ouro? A resposta est� nas entrelinhas: o tesouro que voc� busca � protegido pelo seu maior medo. N�o me entenda mal, a pilha de ouro tamb�m � s� uma met�fora, assim como a grandiosa besta que nem sequer existe. Encontre o seu drag�o e derrote-o, a� ent�o o seu tesouro ser� revelado. Esse � o conhecimento que os antigos contadores de hist�rias queriam transmitir, s� que eles n�o tinham o m�todo cient�fico, nem um modelo para estruturar seus argumentos, e nem sequer uma audi�ncia com QI elevado. Nem por isso a li��o � menos importante hoje em dia. Aquilo que voc� realmente precisa descobrir dentro de si est� escondido onde voc� menos quer buscar. Pergunte a si mesmo: por que voc� estava t�o curioso para abrir o arm�rio? Por acaso voc� � uma pessoa muito escrupulosa, inexoravelmente olhando sob cada pedra que passa? Ou ser� que voc� n�o dominou suas inseguran�as, e o medo de perder alguma coisa � o que te move nesse momento? Talvez voc� esteja simplesmente querendo rir de alguma fala inesperada? Pois vou admitir que eu poderia arruinar todo o clima agora e contar a voc� sobre o palha�o depressivo que tentou se animar comendo um prato de confete. O que eu quero dizer � que, independente do motivo que o trouxe at� aqui, voc� claramente demonstrou curiosidade, e f� de que o mundo guarda surpresas para aqueles dispostos a dar uma olhada sincera. Apesar de isso certamente ser verdade sobre o mundo, � ainda mais verdade sobre seu eu interior. Agora, se isso � assustador, inspirador ou encorajador, depende totalmente de qu�o longe voc� chegou em sua jornada de crescimento pessoal. A vida � feita de v�rias provas, e a maioria delas vai aparecer para voc� mais de uma vez. Trai��o, alegria, doen�a, aventura, falsidade, coopera��o, inten��o, solid�o, gentileza, lealdade... De fato, assim como as velhas e as novas hist�rias, a vida tem temas recorrentes para testar os humanos. A parte importante n�o � saber se voc� passou ou n�o no teste, mas comparecer, ver seu resultado e ponderar sobre como isso pode mostrar o ser que voc� deve se tornar. A partir disso, tudo est� dentro de voc� para ajud�-lo a encontrar seu pr�prio caminho. Vai saber, talvez o sentido principal da hist�ria do Her�i possa at� fazer sentido para voc�. Mas, por ora, vamos voltar para a sua aventura."
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
        printf("\nN�o foi poss�vel abrir o arquivo.");
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
            fprintf(arq, "Modo Dif�cil!!!!\n");
        }

        fprintf(arq, "Quantidade de po��es: %d\n", qPoc);

        //Checa se venceu ou n�o
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

    //Valor para selecionar op��o
    int op;

    //Ataques criticos
    srand( (unsigned)time(NULL) );
    int crit;

    //Variavel de ataque personagem/ataque inimigo
    int ata, ataen;

    //Resto da vida
    int remain;

    //Quantidade po��es
    int qPoc;

    //Chance de ??? acertar/conseguir correr
    int certo, correr;

    //Quantidade de po��es por dificuldade
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
            printf("----- Voc� escolheu o modo imposs�vel! (0 po��es) -----\n\n\n");
            dif = 0;
            qPoc = 0;
            break;
    }

    while(turno < 10)
    {

        //Randomiza valor do critico
        crit = rand() % 10;

        printf("Turno [%d/10]\n", turno+1);

        //Escolha de a��o
        printf("Selecione sua a��o: \n \n1 - Atacar \n2 - Cura \n3 - ??? \n4 - Correr\n");

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
                //Tira uma po��o do invent�rio
                qPoc--;

                //Se vida estiver igual a vida total (tem que adicionar um if ao cima de tudo para ver se tem po��o)
                if(x->vida == x->vidaTot)
                {
                    printf("\nSua vida est� cheia!\n\n");
                    qPoc++;

                }

                //Quando usar a po��o el� iria encher 20 (pode mudar para qualquer valor),
                //entretanto como ia ser maior que a vida total ent�o � melhor utilizar o resto de vida que tinha
                else if(x->vida >= (x->vidaTot - 20))
                {
                    x->vida += remain;
                    printf("\nVoc� recuperou %d de vida! Sua vida est� cheia!\n", remain);
                    printf("\nVoc� tem %d po��es no momento\n", qPoc);

                }
                //Recupera 20 de vida
                else
                {
                    x->vida += 20;
                    printf("\nVoce recuperou 20 de vida!\nSua vida: %d/%d\n", x->vida, x->vidaTot);
                    printf("\nVoc� tem %d po��es no momento\n", qPoc);

                }


            }
            else
            {
                printf("\nVoc� est� sem po��es!\n");
            }

            break;

        //???
        case 3:

            //1/3 de chance de acertar
            certo = rand() % 3;

            printf("\n%s\n", listPiadas());

            //A��o deu certo
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

            //Corre (no momento s� vai para o menu principal)
            if(correr == 1)
            {
                printf("\nVoce conseguiu correr do inimigo! O que n�o sabia, � que nessa hist�ria n�o h� lugar aos fracos.");
                filecg(x->nome, dif, qPoc, turno+1);
                limparTela();
                return 1;
            }

            //Falhou
            else
            {
                printf("\nVoc� n�o conseguiu correr\n");
            }

            break;

        default:
            printf("Op��o inv�lida!!!\n");
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
            printf("Bem, o Her�i n�o era um dos mais capazes do reino... Ele se juntou a mim lutando contra um simples lacaio do Rei Dem�nio\n");
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

        //Tela de parab�ns
        if(y->vida <= 0)
        {
            printf("Voc� derrotou %s!\nHP atual: %d/%d\n", iNome, x->vida, x->vidaTot);

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
    printf("\n1) Come�ar a Aventura");
    printf("\n2) Desistir da Aventura");

    printf("\n\nEscolha a op��o desejada: ");
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
        printf("Escolha sua dificuldade: \n \n1 - F�cil\n2 - Normal\n3 - D�ficil\n>> ");
        scanf("%d", &dif);

        pe.dif = dif;

        //Narrador
        system("cls");
        printf("De todas as hist�rias contadas pelos nossos antepassados, nenhuma se compara a de %s.\nO �nico que conseguiu salvar a Princesa das garras do tem�vel, Rei Dem�nio, em uma aventura anterior.\nA nossa hist�ria come�a na entrada do castelo, onde %s tomou uma decis�o crucial.", pe.nome, pe.nome);
        limparTela();

        //Parte 1
        printf("Voc� deseja mesmo abrir o port�o? (s/n)\n(Escreve p nessa se��o se quiser pular o di�logo)\n>> ");
        fflush(stdin);
        scanf("%s", &yesno);
        system("cls");

        if(yesno == 'p' || yesno == 'P')
        {
            //Come�a batalha
            system("cls");
            batalha(&pe, &ce, pe.dif);
            break;
        }
        // Parte 2
        else if(yesno == 's' || yesno == 'S')
        {
            yesno = ' ';
            printf("Deseja mesmo, realmente abrir este port�o? (s/n)\n>> ");
            scanf("%s", &yesno);

            //Parte 3
            if(yesno == 's' || yesno == 'S')
            {
                system("cls");
                yesno = ' ';
                printf("� A �LTIMA VEZ QUE EU PERGUNTO, ACREDITE EM MIM, VOC� SOFRER� E PODE NUNCA MAIS VOLTAR.\nTROCARIA SUA VIDA PARA SALVAR UMA PRINCESA QUE NEM SABEMOS SE EST� MESMO NESSE CASTELO? (s/n)\n>> ");
                scanf("%s", &yesno);

                //Come�a batalha
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
                    printf("Meu Deus, %s... Chegou at� aqui e desistiu assim...", pe.nome);
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
            printf("Mas essa hist�ria, por mais heroica que seja, n�o foi protagonizada por %s.\nNa realidade, esse se acovardou e desistiu de tudo� Desde todas as riquezas que o esperavam, at� o seu grande amor.", pe.nome);
        }

    case 2:
        printf("\n\nCara, voc� nem se esfor�ou um pouquinho... FIM DE JOGO!!!\n");
        limparTela();
        return 0;
    default:
        printf("\n\nAcho que esse jogador n�o � o Her�i n�o. Ele n�o conseguiu nem digitar o comando correto!!!");
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
