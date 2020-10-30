
void TelaMenuProfessor()
{

    int opcao;

    do{

    system("cls");

    printf("---------------------------\n");
    printf("    Menu Professores\n");
    printf("---------------------------\n");
    printf("1) *Cadastrar Professores\n");
    printf("2) *Consulta de Professores\n");
    printf("3) *Alteracao de Professores\n");
    printf("4) *Exclusao de Professores\n");
    printf("0) *Cancelar\n");
    printf("---------------------------\n");

    scanf("%d", &opcao);


    switch (opcao){
        case 1:
            cadastrarProfessor(*professores, &professoresCadastrados);
            break;
        
        case 2: 
            consultarProfessor();
            break;

        case 3:
            alterarProfessor();
            break;

        case 4:
            excluirProfessor();
            break;

        case 0:
            break;
    }
    }while(opcao != 0);


}


void cadastrarProfessor(Professor* professores, int* professoresCadastrados){

    int opcao;

    professoresCadastrados+=1;

    professores[*professoresCadastrados].codigoProfessor = professoresCadastrados;

    printf("Digite o nome do professor que será cadastrado\n");
    fgets(professores[*professoresCadastrados].nome, 255, stdin);

    printf("\nDigite o código para a modalidade lecionada\n");
    scanf("%d", professores[*professoresCadastrados].modalidadeLecionada);

    printf("\nDigite a data de nascimento. Exemplo: 00/00/0000\n");
    fgets(professores[*professoresCadastrados].dataDeNascimento, 10, stdin);

    printf("\nDigite o local de nascimento\n");
    fgets(professores[*professoresCadastrados].localDeNascimento, 255, stdin);

    printf("Inserir:\n");
    printf("1) CPF\n");
    printf("2) CNPJ\n");

    switch (opcao)
    {
    case 1:
       printf("\nDigite o CPF\n");
       scanf("%d", professores[*professoresCadastrados].CPF);
        break;
    case 2:
        printf("\nDigite o CNPJ\n");
        scanf("%d", professores[*professoresCadastrados].CNPJ);
        break;
    
    default:
        printf("\nDigite o CPF\n");
        scanf("%d", professores[*professoresCadastrados].CPF);
        break;
    }

    printf("\nDigite o endereço da residência\n");
    fgets(professores[*professoresCadastrados].endereco, 255, stdin);

    printf("\nDigite o salário por aluno\n");
    scanf("%f", professores[*professoresCadastrados].salarioPorAluno);

    printf("\nDigite o número da sala que será usada por ele(a)\n");
    scanf("%d", professores[*professprofessoresCadastrados].salaUsada);


    printf("\n Horários disponíveis\n\n");
    printf("dom     |seg    |ter    |qua    |qui    |sex    |sab\n");
    for(i = 0; i < 7; i++){
        if(salas[nsalas].horarios[i][0] == 1)
            printf("disponível  ");
        else
            printf("indiponível  ");
        
    }

    printf("\n");

    for(i = 0; i < 7; i++){
        if(salas[nsalas].horarios[i][1] == 1)
            printf("disponível  ");
        else
            printf("indiponível  ");
        
    }

    printf("\n");

    for(i = 0; i < 7; i++){
        if(salas[nsalas].horarios[i][2] == 1)
            printf("disponível  ");
        else
            printf("indiponível  ");
        
    }


    printf("\n");

    printf("Digite o número de horários que serão usados dessa sala\n");
    scanf("%d", &numHorarios);

    printf("\nDigite o(s) horários de acordo com sua linha e coluna (linha = período, coluna = dia) separados por espaço (para linha e coluna) e enter (para outro dia)\n");

    for(i = 0; i < numHorarios; i++){
        scanf("%d %d", professores[*professoresCadastrados].periodoDia, professores[*professoresCadastrados].diaSemana);
    }

    printf("\nCadastro encerrado\n\n");

    free(opcao);

}

void alterarProfessor(Professor *professores, int* professoresCadastrados){
    int opcao = 1, codigo;


    printf("\nQual o código do professor que deseja alterar>\n");
    scanf("%d", &codigo);


    while(opcao != 0){
        printf("---------------------------\n");
        printf("    O que deseja alterar?\n");
        printf("---------------------------\n");
        printf("1) *Nome\n");
        printf("2) *Modalidade Lecionada\n");
        printf("3) *Local de Nascimento\n");
        printf("4) *Data de nascimento\n");
        printf("5) *RG\n");
        printf("6) *CPF\n");
        printf("7) *CNPJ\n");
        printf("8) *Endereço\n");
        printf("9) *Salario por aluno\n");
        printf("10) *Sala usada\n");
        printf("11) *Dias da semana em que a sala é usada\n");
        printf("12) *Períodos do dia em que a sala é usada\n");
        printf("0) *Cancelar\n");
        printf("---------------------------\n");

        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("\n\nO nome registrado é:");
                fputs(professores[codigo].nome, stdout);

                printf("\n\nQual o novo nome?\n");
                fgets(professores[codigo].nome, 255, stdin);
                break;

            case 2:
                printf("\n\nA modalidade lecionada é a de código %d", );

                printf("\n\nQual o código da modalidade que será lecionada a partir de hoje?\n");// ARRUMAR ISSO AQUI
                scanf("%d", );
                break;

            case 3:
                printf("\n\nO local de nascimento está registrado como:");
                fputs(professores[codigo].localDeNascimento, stdout);

                printf("\n\nDigite o local de nascimento\n");
                fgets(professores[codigo].localDeNascimento, 100, stdin);
                break;

            case 4:
                printf("\n\nA data de nascimento está registrada como sendo");
                fputs(professores[codigo].dataDeNascimento, stdout);

                printf("\n\nDigite a data correta\n");
                fgets(professores[codigo].dataDeNascimento, 10, stdin);
                break;

            case 5:
                printf("\n\nO RG registrado é: %d", professores[codigo].RG);

                printf("\n\nDigite o RG correto\n");
                scanf("%d", professores[codigo].RG);
                break;

            case 6:

                if(professores[codigo].CPF == 0){
                    printf("\n\nNenhum CPF registrado\n");
                }else{
                    printf("\n\nO CPF registrado é: %d");
                }
                
                printf("Digite o CPF correto\n");
                scanf("%d", professores[codigo].CPF);
                
                break;

            case 7:

                if(professores[codigo].CNPJ == 0){
                    printf("\n\nNenhum CNPJ registrado\n");
                }else{
                    printf("\n\nO CNPJ registrado é: %d");
                }
                
                printf("Digite o CNPJ correto\n");
                scanf("%d", professores[codigo].CNPJ);

                break;

            case 8:

                printf("\n\nO endereço registrado é:");
                fputs(professores[codigo].endereco, stdout);

                printf("\n\nDigite o novo endereço\n");
                fgets(professores[codigo].endereco, stdin);
                break;

            case 9:
                printf("\n\nO salário por aluno desse professor é de: R$ %2.f", professores[codigo].salarioPorAluno);

                printf("\n\nDigite o salário atualizado\n");
                scanf("%f", professores[codigo].salarioPorAluno);
                break;

            case 10:
                printf("\n\nA sala utilizada atualmente é a sala de número %d", professores[codigo].salaUsada);

                scanf("%d", salaPretendida);

                for
                break;

            case 11:

                break;

            case 12:

                break;

            case 0:
                break;
            default:
                printf("\nNenhuma das opções selecionadas. Por favor, selecione uma opção válida\n");
        }



    }

    free(opcao);
    free(codigo);

}

void excluirProfessor(Professor *professores, int* professoresCadastrados){


}

void consultarProfessor(Professor *professores, int* professoresCadastrados){

}