#pragma once
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Estructura para el filtro generado.
 */
typedef struct filter {
    double x0;  /// < Estado de la señal en el nodo 0
    double x1;  /// < Estado de la señal en el nodo 1
    double x4;  /// < Estado de la señal en el nodo 4
    double x7;  /// < Estado de la señal en el nodo 7
    double x8;  /// < Estado de la señal en el nodo 8
    double x9;  /// < Estado de la señal en el nodo 9
    double x10;  /// < Estado de la señal en el nodo 10
    double x11;  /// < Estado de la señal en el nodo 11
    double x12;  /// < Estado de la señal en el nodo 12
    double x13;  /// < Estado de la señal en el nodo 13
    double x14;  /// < Estado de la señal en el nodo 14
    double x16;  /// < Estado de la señal en el nodo 16
    double x17;  /// < Estado de la señal en el nodo 17
    double x18;  /// < Estado de la señal en el nodo 18
    double x19;  /// < Estado de la señal en el nodo 19
    double g_0_1;  /// < Ganancia de x0 a x1
    double g_0_9;  /// < Ganancia de x0 a x9
    double g_0_13;  /// < Ganancia de x0 a x13
    double g_0_16;  /// < Ganancia de x0 a x16
    double g_1_7;  /// < Ganancia de x1 a x7
    double g_1_8;  /// < Ganancia de x1 a x8
    double d_1_10[19];  /// < Buffer de retardo de x1 a x10 (tamaño: 19)
    int pos_d_1_10;  /// < Posición actual del retardo de x1 a x10
    double g_1_12;  /// < Ganancia de x1 a x12
    double g_1_18;  /// < Ganancia de x1 a x18
    double g_4_7;  /// < Ganancia de x4 a x7
    double g_4_8;  /// < Ganancia de x4 a x8
    double g_4_18;  /// < Ganancia de x4 a x18
    double g_4_19;  /// < Ganancia de x4 a x19
    double d_7_1[9];  /// < Buffer de retardo de x7 a x1 (tamaño: 9)
    int pos_d_7_1;  /// < Posición actual del retardo de x7 a x1
    double g_7_8;  /// < Ganancia de x7 a x8
    double g_7_11;  /// < Ganancia de x7 a x11
    double g_7_12;  /// < Ganancia de x7 a x12
    double g_7_14;  /// < Ganancia de x7 a x14
    double g_7_17;  /// < Ganancia de x7 a x17
    double d_8_4[3];  /// < Buffer de retardo de x8 a x4 (tamaño: 3)
    int pos_d_8_4;  /// < Posición actual del retardo de x8 a x4
    double g_8_9;  /// < Ganancia de x8 a x9
    double g_8_12;  /// < Ganancia de x8 a x12
    double g_8_14;  /// < Ganancia de x8 a x14
    double d_9_0[1];  /// < Buffer de retardo de x9 a x0 (tamaño: 1)
    int pos_d_9_0;  /// < Posición actual del retardo de x9 a x0
    double d_9_8[17];  /// < Buffer de retardo de x9 a x8 (tamaño: 17)
    int pos_d_9_8;  /// < Posición actual del retardo de x9 a x8
    double g_9_13;  /// < Ganancia de x9 a x13
    double g_9_17;  /// < Ganancia de x9 a x17
    double g_9_18;  /// < Ganancia de x9 a x18
    double g_10_12;  /// < Ganancia de x10 a x12
    double g_10_14;  /// < Ganancia de x10 a x14
    double g_10_18;  /// < Ganancia de x10 a x18
    double g_11_13;  /// < Ganancia de x11 a x13
    double g_11_14;  /// < Ganancia de x11 a x14
    double g_11_16;  /// < Ganancia de x11 a x16
    double g_11_17;  /// < Ganancia de x11 a x17
    double g_11_18;  /// < Ganancia de x11 a x18
    double g_11_19;  /// < Ganancia de x11 a x19
    double d_12_1[3];  /// < Buffer de retardo de x12 a x1 (tamaño: 3)
    int pos_d_12_1;  /// < Posición actual del retardo de x12 a x1
    double d_12_4[19];  /// < Buffer de retardo de x12 a x4 (tamaño: 19)
    int pos_d_12_4;  /// < Posición actual del retardo de x12 a x4
    double d_12_7[12];  /// < Buffer de retardo de x12 a x7 (tamaño: 12)
    int pos_d_12_7;  /// < Posición actual del retardo de x12 a x7
    double d_12_8[3];  /// < Buffer de retardo de x12 a x8 (tamaño: 3)
    int pos_d_12_8;  /// < Posición actual del retardo de x12 a x8
    double g_12_16;  /// < Ganancia de x12 a x16
    double d_13_0[14];  /// < Buffer de retardo de x13 a x0 (tamaño: 14)
    int pos_d_13_0;  /// < Posición actual del retardo de x13 a x0
    double d_13_4[15];  /// < Buffer de retardo de x13 a x4 (tamaño: 15)
    int pos_d_13_4;  /// < Posición actual del retardo de x13 a x4
    double d_13_7[11];  /// < Buffer de retardo de x13 a x7 (tamaño: 11)
    int pos_d_13_7;  /// < Posición actual del retardo de x13 a x7
    double d_13_9[13];  /// < Buffer de retardo de x13 a x9 (tamaño: 13)
    int pos_d_13_9;  /// < Posición actual del retardo de x13 a x9
    double d_13_11[9];  /// < Buffer de retardo de x13 a x11 (tamaño: 9)
    int pos_d_13_11;  /// < Posición actual del retardo de x13 a x11
    double d_13_14[36];  /// < Buffer de retardo de x13 a x14 (tamaño: 36)
    int pos_d_13_14;  /// < Posición actual del retardo de x13 a x14
    double d_13_16[12];  /// < Buffer de retardo de x13 a x16 (tamaño: 12)
    int pos_d_13_16;  /// < Posición actual del retardo de x13 a x16
    double g_13_17;  /// < Ganancia de x13 a x17
    double d_13_19[33];  /// < Buffer de retardo de x13 a x19 (tamaño: 33)
    int pos_d_13_19;  /// < Posición actual del retardo de x13 a x19
    double d_14_7[2];  /// < Buffer de retardo de x14 a x7 (tamaño: 2)
    int pos_d_14_7;  /// < Posición actual del retardo de x14 a x7
    double d_14_11[21];  /// < Buffer de retardo de x14 a x11 (tamaño: 21)
    int pos_d_14_11;  /// < Posición actual del retardo de x14 a x11
    double g_14_19;  /// < Ganancia de x14 a x19
    double d_16_0[1];  /// < Buffer de retardo de x16 a x0 (tamaño: 1)
    int pos_d_16_0;  /// < Posición actual del retardo de x16 a x0
    double d_16_7[2];  /// < Buffer de retardo de x16 a x7 (tamaño: 2)
    int pos_d_16_7;  /// < Posición actual del retardo de x16 a x7
    double g_16_17;  /// < Ganancia de x16 a x17
    double g_16_19;  /// < Ganancia de x16 a x19
    double d_17_7[15];  /// < Buffer de retardo de x17 a x7 (tamaño: 15)
    int pos_d_17_7;  /// < Posición actual del retardo de x17 a x7
    double d_17_9[4];  /// < Buffer de retardo de x17 a x9 (tamaño: 4)
    int pos_d_17_9;  /// < Posición actual del retardo de x17 a x9
    double d_17_11[6];  /// < Buffer de retardo de x17 a x11 (tamaño: 6)
    int pos_d_17_11;  /// < Posición actual del retardo de x17 a x11
    double d_17_13[30];  /// < Buffer de retardo de x17 a x13 (tamaño: 30)
    int pos_d_17_13;  /// < Posición actual del retardo de x17 a x13
    double d_17_16[1];  /// < Buffer de retardo de x17 a x16 (tamaño: 1)
    int pos_d_17_16;  /// < Posición actual del retardo de x17 a x16
    double d_18_1[5];  /// < Buffer de retardo de x18 a x1 (tamaño: 5)
    int pos_d_18_1;  /// < Posición actual del retardo de x18 a x1
    double d_18_4[8];  /// < Buffer de retardo de x18 a x4 (tamaño: 8)
    int pos_d_18_4;  /// < Posición actual del retardo de x18 a x4
    double d_18_9[14];  /// < Buffer de retardo de x18 a x9 (tamaño: 14)
    int pos_d_18_9;  /// < Posición actual del retardo de x18 a x9
    double d_18_11[9];  /// < Buffer de retardo de x18 a x11 (tamaño: 9)
    int pos_d_18_11;  /// < Posición actual del retardo de x18 a x11
    double d_18_13[1];  /// < Buffer de retardo de x18 a x13 (tamaño: 1)
    int pos_d_18_13;  /// < Posición actual del retardo de x18 a x13
    double d_19_11[1];  /// < Buffer de retardo de x19 a x11 (tamaño: 1)
    int pos_d_19_11;  /// < Posición actual del retardo de x19 a x11
} filter_t;

/**
 * @brief Esta función debe ser llamada antes de comenzar a procesar audio.
 *
 * @param f Puntero a una estructura del filtro generado.
 */
inline void filter_init(filter_t* f)
{
    f->x0 = 0.0f;
    f->x1 = 0.0f;
    f->x4 = 0.0f;
    f->x7 = 0.0f;
    f->x8 = 0.0f;
    f->x9 = 0.0f;
    f->x10 = 0.0f;
    f->x11 = 0.0f;
    f->x12 = 0.0f;
    f->x13 = 0.0f;
    f->x14 = 0.0f;
    f->x16 = 0.0f;
    f->x17 = 0.0f;
    f->x18 = 0.0f;
    f->x19 = 0.0f;

    // Inicialización de retardos
    f->g_0_1 = -1.863995773731528e+00;
    f->g_0_9 = 8.137883552521619e-03;
    f->g_0_13 = 2.836874858547481e-03;
    f->g_0_16 = 2.031941073490552e-02;
    f->g_1_7 = 9.551393457511704e-03;
    f->g_1_8 = 1.000000000000000e+00;
    for (int k = 0; k < 19; k++) f->d_1_10[k] = 0.0f;
    f->pos_d_1_10 = 0;
    f->g_1_12 = -2.893098002090931e-04;
    f->g_1_18 = -7.073077845195185e-03;
    f->g_4_7 = -2.014476729339010e-01;
    f->g_4_8 = -3.620604539894006e-02;
    f->g_4_18 = 7.256776995162345e-04;
    f->g_4_19 = -4.545343240135864e-03;
    for (int k = 0; k < 9; k++) f->d_7_1[k] = 0.0f;
    f->pos_d_7_1 = 0;
    f->g_7_8 = 1.591351422228491e+00;
    f->g_7_11 = -1.835395088330357e+00;
    f->g_7_12 = 5.935124253595039e-02;
    f->g_7_14 = -1.452285446932693e-01;
    f->g_7_17 = 1.935676201142311e-02;
    for (int k = 0; k < 3; k++) f->d_8_4[k] = 0.0f;
    f->pos_d_8_4 = 0;
    f->g_8_9 = -2.694350925733554e-02;
    f->g_8_12 = 1.530458334495390e-03;
    f->g_8_14 = -1.564476321401828e-03;
    for (int k = 0; k < 1; k++) f->d_9_0[k] = 0.0f;
    f->pos_d_9_0 = 0;
    for (int k = 0; k < 17; k++) f->d_9_8[k] = 0.0f;
    f->pos_d_9_8 = 0;
    f->g_9_13 = -4.307669342007218e-02;
    f->g_9_17 = 3.041222412711399e-02;
    f->g_9_18 = -2.267791182118166e-02;
    f->g_10_12 = 1.380735325704432e-03;
    f->g_10_14 = 8.983395986895317e-03;
    f->g_10_18 = -1.001517357594095e-03;
    f->g_11_13 = 2.074690684469576e-02;
    f->g_11_14 = 1.298091443627209e-02;
    f->g_11_16 = -1.934468426808327e-01;
    f->g_11_17 = -3.433615628130961e-04;
    f->g_11_18 = 4.487355443475475e-03;
    f->g_11_19 = -4.913232902111898e-02;
    for (int k = 0; k < 3; k++) f->d_12_1[k] = 0.0f;
    f->pos_d_12_1 = 0;
    for (int k = 0; k < 19; k++) f->d_12_4[k] = 0.0f;
    f->pos_d_12_4 = 0;
    for (int k = 0; k < 12; k++) f->d_12_7[k] = 0.0f;
    f->pos_d_12_7 = 0;
    for (int k = 0; k < 3; k++) f->d_12_8[k] = 0.0f;
    f->pos_d_12_8 = 0;
    f->g_12_16 = -2.357172842726420e-02;
    for (int k = 0; k < 14; k++) f->d_13_0[k] = 0.0f;
    f->pos_d_13_0 = 0;
    for (int k = 0; k < 15; k++) f->d_13_4[k] = 0.0f;
    f->pos_d_13_4 = 0;
    for (int k = 0; k < 11; k++) f->d_13_7[k] = 0.0f;
    f->pos_d_13_7 = 0;
    for (int k = 0; k < 13; k++) f->d_13_9[k] = 0.0f;
    f->pos_d_13_9 = 0;
    for (int k = 0; k < 9; k++) f->d_13_11[k] = 0.0f;
    f->pos_d_13_11 = 0;
    for (int k = 0; k < 36; k++) f->d_13_14[k] = 0.0f;
    f->pos_d_13_14 = 0;
    for (int k = 0; k < 12; k++) f->d_13_16[k] = 0.0f;
    f->pos_d_13_16 = 0;
    f->g_13_17 = -4.464777141857126e-01;
    for (int k = 0; k < 33; k++) f->d_13_19[k] = 0.0f;
    f->pos_d_13_19 = 0;
    for (int k = 0; k < 2; k++) f->d_14_7[k] = 0.0f;
    f->pos_d_14_7 = 0;
    for (int k = 0; k < 21; k++) f->d_14_11[k] = 0.0f;
    f->pos_d_14_11 = 0;
    f->g_14_19 = -2.943606937733928e-01;
    for (int k = 0; k < 1; k++) f->d_16_0[k] = 0.0f;
    f->pos_d_16_0 = 0;
    for (int k = 0; k < 2; k++) f->d_16_7[k] = 0.0f;
    f->pos_d_16_7 = 0;
    f->g_16_17 = -1.325160956033234e-02;
    f->g_16_19 = 1.887267240661118e+00;
    for (int k = 0; k < 15; k++) f->d_17_7[k] = 0.0f;
    f->pos_d_17_7 = 0;
    for (int k = 0; k < 4; k++) f->d_17_9[k] = 0.0f;
    f->pos_d_17_9 = 0;
    for (int k = 0; k < 6; k++) f->d_17_11[k] = 0.0f;
    f->pos_d_17_11 = 0;
    for (int k = 0; k < 30; k++) f->d_17_13[k] = 0.0f;
    f->pos_d_17_13 = 0;
    for (int k = 0; k < 1; k++) f->d_17_16[k] = 0.0f;
    f->pos_d_17_16 = 0;
    for (int k = 0; k < 5; k++) f->d_18_1[k] = 0.0f;
    f->pos_d_18_1 = 0;
    for (int k = 0; k < 8; k++) f->d_18_4[k] = 0.0f;
    f->pos_d_18_4 = 0;
    for (int k = 0; k < 14; k++) f->d_18_9[k] = 0.0f;
    f->pos_d_18_9 = 0;
    for (int k = 0; k < 9; k++) f->d_18_11[k] = 0.0f;
    f->pos_d_18_11 = 0;
    for (int k = 0; k < 1; k++) f->d_18_13[k] = 0.0f;
    f->pos_d_18_13 = 0;
    for (int k = 0; k < 1; k++) f->d_19_11[k] = 0.0f;
    f->pos_d_19_11 = 0;
}

/**
 * @brief Esta función resetea el estado del filtro, incluyendo sus buffers de retardo y sus variables de estado.
 *
 * @param f Puntero a una estructura del filtro generado.
 */
inline void filter_reset(filter_t* f)
{
    f->x0 = 0.0f;
    f->x1 = 0.0f;
    f->x4 = 0.0f;
    f->x7 = 0.0f;
    f->x8 = 0.0f;
    f->x9 = 0.0f;
    f->x10 = 0.0f;
    f->x11 = 0.0f;
    f->x12 = 0.0f;
    f->x13 = 0.0f;
    f->x14 = 0.0f;
    f->x16 = 0.0f;
    f->x17 = 0.0f;
    f->x18 = 0.0f;
    f->x19 = 0.0f;
    for (int k = 0; k < 19; k++) f->d_1_10[k] = 0.0f;
    f->pos_d_1_10 = 0;
    for (int k = 0; k < 9; k++) f->d_7_1[k] = 0.0f;
    f->pos_d_7_1 = 0;
    for (int k = 0; k < 3; k++) f->d_8_4[k] = 0.0f;
    f->pos_d_8_4 = 0;
    for (int k = 0; k < 1; k++) f->d_9_0[k] = 0.0f;
    f->pos_d_9_0 = 0;
    for (int k = 0; k < 17; k++) f->d_9_8[k] = 0.0f;
    f->pos_d_9_8 = 0;
    for (int k = 0; k < 3; k++) f->d_12_1[k] = 0.0f;
    f->pos_d_12_1 = 0;
    for (int k = 0; k < 19; k++) f->d_12_4[k] = 0.0f;
    f->pos_d_12_4 = 0;
    for (int k = 0; k < 12; k++) f->d_12_7[k] = 0.0f;
    f->pos_d_12_7 = 0;
    for (int k = 0; k < 3; k++) f->d_12_8[k] = 0.0f;
    f->pos_d_12_8 = 0;
    for (int k = 0; k < 14; k++) f->d_13_0[k] = 0.0f;
    f->pos_d_13_0 = 0;
    for (int k = 0; k < 15; k++) f->d_13_4[k] = 0.0f;
    f->pos_d_13_4 = 0;
    for (int k = 0; k < 11; k++) f->d_13_7[k] = 0.0f;
    f->pos_d_13_7 = 0;
    for (int k = 0; k < 13; k++) f->d_13_9[k] = 0.0f;
    f->pos_d_13_9 = 0;
    for (int k = 0; k < 9; k++) f->d_13_11[k] = 0.0f;
    f->pos_d_13_11 = 0;
    for (int k = 0; k < 36; k++) f->d_13_14[k] = 0.0f;
    f->pos_d_13_14 = 0;
    for (int k = 0; k < 12; k++) f->d_13_16[k] = 0.0f;
    f->pos_d_13_16 = 0;
    for (int k = 0; k < 33; k++) f->d_13_19[k] = 0.0f;
    f->pos_d_13_19 = 0;
    for (int k = 0; k < 2; k++) f->d_14_7[k] = 0.0f;
    f->pos_d_14_7 = 0;
    for (int k = 0; k < 21; k++) f->d_14_11[k] = 0.0f;
    f->pos_d_14_11 = 0;
    for (int k = 0; k < 1; k++) f->d_16_0[k] = 0.0f;
    f->pos_d_16_0 = 0;
    for (int k = 0; k < 2; k++) f->d_16_7[k] = 0.0f;
    f->pos_d_16_7 = 0;
    for (int k = 0; k < 15; k++) f->d_17_7[k] = 0.0f;
    f->pos_d_17_7 = 0;
    for (int k = 0; k < 4; k++) f->d_17_9[k] = 0.0f;
    f->pos_d_17_9 = 0;
    for (int k = 0; k < 6; k++) f->d_17_11[k] = 0.0f;
    f->pos_d_17_11 = 0;
    for (int k = 0; k < 30; k++) f->d_17_13[k] = 0.0f;
    f->pos_d_17_13 = 0;
    for (int k = 0; k < 1; k++) f->d_17_16[k] = 0.0f;
    f->pos_d_17_16 = 0;
    for (int k = 0; k < 5; k++) f->d_18_1[k] = 0.0f;
    f->pos_d_18_1 = 0;
    for (int k = 0; k < 8; k++) f->d_18_4[k] = 0.0f;
    f->pos_d_18_4 = 0;
    for (int k = 0; k < 14; k++) f->d_18_9[k] = 0.0f;
    f->pos_d_18_9 = 0;
    for (int k = 0; k < 9; k++) f->d_18_11[k] = 0.0f;
    f->pos_d_18_11 = 0;
    for (int k = 0; k < 1; k++) f->d_18_13[k] = 0.0f;
    f->pos_d_18_13 = 0;
    for (int k = 0; k < 1; k++) f->d_19_11[k] = 0.0f;
    f->pos_d_19_11 = 0;
}

/**
 * @brief Procesa una señal de audio mediante el filtro generado.
 *
 * @param f Puntero a una estructura del filtro generado.
 * @param input Puntero a la señal de entrada. Debe tener al menos `num_samples` muestras.
 * @param output Puntero a la señal de salida. Debe tener al menos `num_samples` muestras.
 * @param num_samples Número de muestras a procesar.
 */
inline void filter_process(filter_t* f, const float* input, float* output, int num_samples)
{
    for (int n = 0; n < num_samples; n++) {
        // x0
        f->x0 = input[n] + f->d_9_0[f->pos_d_9_0] + f->d_13_0[f->pos_d_13_0] + f->d_16_0[f->pos_d_16_0];

        // x1
        f->x1 = 0.0f + f->d_7_1[f->pos_d_7_1] + f->d_12_1[f->pos_d_12_1] + f->d_18_1[f->pos_d_18_1];
        f->x1 += f->g_0_1 * f->x0;

        // x4
        f->x4 = 0.0f + f->d_8_4[f->pos_d_8_4] + f->d_12_4[f->pos_d_12_4] + f->d_13_4[f->pos_d_13_4] + f->d_18_4[f->pos_d_18_4];

        // x7
        f->x7 = 0.0f + f->d_12_7[f->pos_d_12_7] + f->d_13_7[f->pos_d_13_7] + f->d_14_7[f->pos_d_14_7] + f->d_16_7[f->pos_d_16_7] + f->d_17_7[f->pos_d_17_7];
        f->x7 += f->g_1_7 * f->x1;
        f->x7 += f->g_4_7 * f->x4;

        // x8
        f->x8 = 0.0f + f->d_9_8[f->pos_d_9_8] + f->d_12_8[f->pos_d_12_8];
        f->x8 += f->g_1_8 * f->x1;
        f->x8 += f->g_4_8 * f->x4;
        f->x8 += f->g_7_8 * f->x7;

        // x9
        f->x9 = 0.0f + f->d_13_9[f->pos_d_13_9] + f->d_17_9[f->pos_d_17_9] + f->d_18_9[f->pos_d_18_9];
        f->x9 += f->g_0_9 * f->x0;
        f->x9 += f->g_8_9 * f->x8;

        // x10
        f->x10 = 0.0f + f->d_1_10[f->pos_d_1_10];

        // x11
        f->x11 = 0.0f + f->d_13_11[f->pos_d_13_11] + f->d_14_11[f->pos_d_14_11] + f->d_17_11[f->pos_d_17_11] + f->d_18_11[f->pos_d_18_11] + f->d_19_11[f->pos_d_19_11];
        f->x11 += f->g_7_11 * f->x7;

        // x12
        f->x12 = 0.0f;
        f->x12 += f->g_1_12 * f->x1;
        f->x12 += f->g_7_12 * f->x7;
        f->x12 += f->g_8_12 * f->x8;
        f->x12 += f->g_10_12 * f->x10;

        // x13
        f->x13 = 0.0f + f->d_17_13[f->pos_d_17_13] + f->d_18_13[f->pos_d_18_13];
        f->x13 += f->g_0_13 * f->x0;
        f->x13 += f->g_9_13 * f->x9;
        f->x13 += f->g_11_13 * f->x11;

        // x14
        f->x14 = 0.0f + f->d_13_14[f->pos_d_13_14];
        f->x14 += f->g_7_14 * f->x7;
        f->x14 += f->g_8_14 * f->x8;
        f->x14 += f->g_10_14 * f->x10;
        f->x14 += f->g_11_14 * f->x11;

        // x16
        f->x16 = 0.0f + f->d_13_16[f->pos_d_13_16] + f->d_17_16[f->pos_d_17_16];
        f->x16 += f->g_0_16 * f->x0;
        f->x16 += f->g_11_16 * f->x11;
        f->x16 += f->g_12_16 * f->x12;

        // x17
        f->x17 = 0.0f;
        f->x17 += f->g_7_17 * f->x7;
        f->x17 += f->g_9_17 * f->x9;
        f->x17 += f->g_11_17 * f->x11;
        f->x17 += f->g_13_17 * f->x13;
        f->x17 += f->g_16_17 * f->x16;

        // x18
        f->x18 = 0.0f;
        f->x18 += f->g_1_18 * f->x1;
        f->x18 += f->g_4_18 * f->x4;
        f->x18 += f->g_9_18 * f->x9;
        f->x18 += f->g_10_18 * f->x10;
        f->x18 += f->g_11_18 * f->x11;

        // x19
        f->x19 = 0.0f + f->d_13_19[f->pos_d_13_19];
        f->x19 += f->g_4_19 * f->x4;
        f->x19 += f->g_11_19 * f->x11;
        f->x19 += f->g_14_19 * f->x14;
        f->x19 += f->g_16_19 * f->x16;

        // Actualización de retardos
        f->d_1_10[f->pos_d_1_10] = f->x1;
        f->pos_d_1_10 = (f->pos_d_1_10 + 1) % 19;
        f->d_7_1[f->pos_d_7_1] = f->x7;
        f->pos_d_7_1 = (f->pos_d_7_1 + 1) % 9;
        f->d_8_4[f->pos_d_8_4] = f->x8;
        f->pos_d_8_4 = (f->pos_d_8_4 + 1) % 3;
        f->d_9_0[f->pos_d_9_0] = f->x9;
        f->pos_d_9_0 = (f->pos_d_9_0 + 1) % 1;
        f->d_9_8[f->pos_d_9_8] = f->x9;
        f->pos_d_9_8 = (f->pos_d_9_8 + 1) % 17;
        f->d_12_1[f->pos_d_12_1] = f->x12;
        f->pos_d_12_1 = (f->pos_d_12_1 + 1) % 3;
        f->d_12_4[f->pos_d_12_4] = f->x12;
        f->pos_d_12_4 = (f->pos_d_12_4 + 1) % 19;
        f->d_12_7[f->pos_d_12_7] = f->x12;
        f->pos_d_12_7 = (f->pos_d_12_7 + 1) % 12;
        f->d_12_8[f->pos_d_12_8] = f->x12;
        f->pos_d_12_8 = (f->pos_d_12_8 + 1) % 3;
        f->d_13_0[f->pos_d_13_0] = f->x13;
        f->pos_d_13_0 = (f->pos_d_13_0 + 1) % 14;
        f->d_13_4[f->pos_d_13_4] = f->x13;
        f->pos_d_13_4 = (f->pos_d_13_4 + 1) % 15;
        f->d_13_7[f->pos_d_13_7] = f->x13;
        f->pos_d_13_7 = (f->pos_d_13_7 + 1) % 11;
        f->d_13_9[f->pos_d_13_9] = f->x13;
        f->pos_d_13_9 = (f->pos_d_13_9 + 1) % 13;
        f->d_13_11[f->pos_d_13_11] = f->x13;
        f->pos_d_13_11 = (f->pos_d_13_11 + 1) % 9;
        f->d_13_14[f->pos_d_13_14] = f->x13;
        f->pos_d_13_14 = (f->pos_d_13_14 + 1) % 36;
        f->d_13_16[f->pos_d_13_16] = f->x13;
        f->pos_d_13_16 = (f->pos_d_13_16 + 1) % 12;
        f->d_13_19[f->pos_d_13_19] = f->x13;
        f->pos_d_13_19 = (f->pos_d_13_19 + 1) % 33;
        f->d_14_7[f->pos_d_14_7] = f->x14;
        f->pos_d_14_7 = (f->pos_d_14_7 + 1) % 2;
        f->d_14_11[f->pos_d_14_11] = f->x14;
        f->pos_d_14_11 = (f->pos_d_14_11 + 1) % 21;
        f->d_16_0[f->pos_d_16_0] = f->x16;
        f->pos_d_16_0 = (f->pos_d_16_0 + 1) % 1;
        f->d_16_7[f->pos_d_16_7] = f->x16;
        f->pos_d_16_7 = (f->pos_d_16_7 + 1) % 2;
        f->d_17_7[f->pos_d_17_7] = f->x17;
        f->pos_d_17_7 = (f->pos_d_17_7 + 1) % 15;
        f->d_17_9[f->pos_d_17_9] = f->x17;
        f->pos_d_17_9 = (f->pos_d_17_9 + 1) % 4;
        f->d_17_11[f->pos_d_17_11] = f->x17;
        f->pos_d_17_11 = (f->pos_d_17_11 + 1) % 6;
        f->d_17_13[f->pos_d_17_13] = f->x17;
        f->pos_d_17_13 = (f->pos_d_17_13 + 1) % 30;
        f->d_17_16[f->pos_d_17_16] = f->x17;
        f->pos_d_17_16 = (f->pos_d_17_16 + 1) % 1;
        f->d_18_1[f->pos_d_18_1] = f->x18;
        f->pos_d_18_1 = (f->pos_d_18_1 + 1) % 5;
        f->d_18_4[f->pos_d_18_4] = f->x18;
        f->pos_d_18_4 = (f->pos_d_18_4 + 1) % 8;
        f->d_18_9[f->pos_d_18_9] = f->x18;
        f->pos_d_18_9 = (f->pos_d_18_9 + 1) % 14;
        f->d_18_11[f->pos_d_18_11] = f->x18;
        f->pos_d_18_11 = (f->pos_d_18_11 + 1) % 9;
        f->d_18_13[f->pos_d_18_13] = f->x18;
        f->pos_d_18_13 = (f->pos_d_18_13 + 1) % 1;
        f->d_19_11[f->pos_d_19_11] = f->x19;
        f->pos_d_19_11 = (f->pos_d_19_11 + 1) % 1;
        output[n] = f->x19;
    }
}

#ifdef __cplusplus
    } // __cplusplus
#endif

