#include "menu.h"

void menu(){
    int op;
    do{
        op = -1;
        cabecalho(0);
        printf("\n1 - Inserir linha\n");
        printf("2 - Remover linha\n");
        printf("3 - Alterar linha\n");
        printf("4 - Listar linhas\n");
        printf("5 - Consultar horários\n");
        printf("6 - Consultar assento disponivel\n");
        printf("7 - Relatórios\n");
        printf("8 - Ler reservas de arquivos texto\n");
        //printf("9 - Mostrar var\n");
        danger("0 - Sair\n");
        printf("OPÇÃO: ");
        // clearBuf();
        scanf("%1d", &op);
        clearBuf();
        opcao(op);
    }while(op != 0);
}

void opcao(int op){
    switch (op){
        case 1:
            cabecalho(1);
            inserirLinha();
            break;
        case 2:
            cabecalho(2);
            removerLinha();
            break;
        case 3:
            cabecalho(3);
            alterarLinha();
            break;
        case 4:
            cabecalho(4);
            listarLinhas();
            break;
        case 5:
            cabecalho(5);
            consultarHorarios();
            break;
        case 6:
            cabecalho(6);
            consultarAssentos();
            break;
        case 7:
            cabecalho(7);
            menuRel();
            break;
        case 8:
            cabecalho(8);
            lerReserva();
            break;
        case 9:
            printf("num_linhas: %d\n",num_linhas);
            printf("cont_lin: %d\n\n",cont_Lin);
            printf("num_onibus: %d\n",num_onibus);
            printf("cont_oni: %d\n",cont_oni);
            Data d;
            d.dia = 11;
            d.mes = 3;
            d.ano = 2019;
            printf("%d\n%d",diffDate(d),getDiaSemana(d)+1);
            break;
        case 0:
            sair();
            break;
        default:
            printf("Opção Invalida!");
            getchar();
            break;
    }
}

void menuRel(){
	int op;
	cabecalho(7);
    printf("\n1 - Total arrecadado (tela)\n");
    printf("2 - Total arrecadado (arquivo)\n");
    printf("3 - Ocupação percentual media (tela)\n");
    printf("4 - Ocupação percentual media (arquivo)\n");
    danger("0 - Voltar\n");
	printf("OPÇÃO: ");
    scanf("%1d", &op);
    clearBuf();
    if(op == 1){
		relArrecTela();
	}else if(op == 2){
		relArrecArq();
	}else if(op == 3){
        relOcupTela();
	}else if(op == 4){
        relOcupArq();
	}
}

void cabecalho(int i){
	if(i == 0){
		printCabecalho("Menu");
    }else if(i == 1){
		printCabecalho("Cadastrar Linha");
	}else if(i == 2){
		printCabecalho("Remover Linha");
	}else if(i == 3){
		printCabecalho("Alterar Linha");
	}else if(i == 4){
		printCabecalho("Listar Linha");
	}else if(i == 5){
		printCabecalho("Consultar Horários");
	}else if(i == 6){
		printCabecalho("Consultar Assentos");
	}else if(i == 7){
		printCabecalho("Relatórios");
	}else if(i == 8){
		printCabecalho("Ler reservas de arquivo texto");
	}else if(i == 9){
		printCabecalho("Relatório Arrecadação Mensal");
	}else if(i == 10){
		printCabecalho("Relatório Ocupacao percentual media");
    }
}

void printCabecalho(char *s){
	cls();
	int t = (int)strlen(s);
	int sp = (49/2) - (t/2);
	printf("/////////////////////////////////////////////////////\n");
    printf("//                                                 //\n//");
	for(int i = 0; i < sp; i++){
		printf(" ");
	}
	printf("%s", s);
	sp = (isPar(t)? (sp+1):(sp));
	for(int i = 0; i < sp; i++){
		printf(" ");
	}
    printf("//\n//                                                 //\n");
    printf("/////////////////////////////////////////////////////\n");
}

void sair(){
    FILE *fp = fopen(bdlin, "wb");
    
    fwrite(&num_linhas, sizeof(int), 1, fp);
    fwrite(&cont_Lin, sizeof(int), 1, fp);
    fwrite(lin, sizeof(Linha), num_linhas, fp);
    free(lin);
    fclose(fp);

    fp = fopen(bdoni, "wb");
    fwrite(&num_onibus, sizeof(int), 1, fp);
    fwrite(&cont_oni, sizeof(int), 1, fp);
    fwrite(oni, sizeof(Onibus), num_onibus, fp);
    free(oni);

    fclose(fp);
    printf("Saindo...\n");
    //getchar();
}