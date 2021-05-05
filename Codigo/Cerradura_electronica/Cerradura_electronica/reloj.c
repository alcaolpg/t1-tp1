
//char masc_hora[] = {0,0,0,0,0,0};
/*El siguiente modulo espera una determinada cantidad de interrupciones de reloj. Cuando sucede dicha cantidad de interrupciones,
el modulo actualiza una mascara de reloj (masc_reloj) que es recivida como parametro mediante un puntero, para luego ser mostrada
en pantalla por la MEF funciones*/

volatile char contador_interrupciones = 0;
volatile char estado_MEF = 1;
char un_segundo = 10; //Suponer que 1int = 100ms



int MEF_reloj (char *masc_hora)
{

    switch (estado_MEF)
    {

    case 1: //Reloj quieto

        estado_MEF = 1;
        contador_interrupciones++;

        if (un_segundo == contador_interrupciones)
        {
            estado_MEF = 2;
        }

        break;
    
    case 2: //Incrementar HH:MM:SS

        estado_MEF = 3;
        contador_interrupciones++;

        masc_hora[5]++;

        if (masc_hora[5] > 9)
        {
            masc_hora[5] = 0;
            masc_hora[4]++;

            if (masc_hora[4] > 5)
            {
                masc_hora[4] = 0;
                masc_hora[3]++;

                if (masc_hora[3] > 9)
                {
                    masc_hora[3] = 0;
                    masc_hora[2]++;

                    if (masc_hora[2] > 5)
                    {
                        masc_hora[2] = 0;
                        masc_hora[1]++;

                        if (masc_hora[1] > 9)
                        {
                            masc_hora[1] = 0;
                            masc_hora[0]++;

                            if (masc_hora[0] > 2)
                            {
                                masc_hora[0] = 0;
                            }
                        }
                    }
                }
            }
        }
        
        break;
        
    default:
        break;
    }
}