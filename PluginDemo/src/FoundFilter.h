#pragma once
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Estructura para el filtro generado.
 */
typedef struct filter {
  double x0;           /// < Estado de la señal en el nodo 0
  double x8;           /// < Estado de la señal en el nodo 8
  double x9;           /// < Estado de la señal en el nodo 9
  double x11;          /// < Estado de la señal en el nodo 11
  double x15;          /// < Estado de la señal en el nodo 15
  double x16;          /// < Estado de la señal en el nodo 16
  double x18;          /// < Estado de la señal en el nodo 18
  double x21;          /// < Estado de la señal en el nodo 21
  double x22;          /// < Estado de la señal en el nodo 22
  double x23;          /// < Estado de la señal en el nodo 23
  double x24;          /// < Estado de la señal en el nodo 24
  double x29;          /// < Estado de la señal en el nodo 29
  double x30;          /// < Estado de la señal en el nodo 30
  double x33;          /// < Estado de la señal en el nodo 33
  double x37;          /// < Estado de la señal en el nodo 37
  double x38;          /// < Estado de la señal en el nodo 38
  double x41;          /// < Estado de la señal en el nodo 41
  double x42;          /// < Estado de la señal en el nodo 42
  double x43;          /// < Estado de la señal en el nodo 43
  double x44;          /// < Estado de la señal en el nodo 44
  double x45;          /// < Estado de la señal en el nodo 45
  double x46;          /// < Estado de la señal en el nodo 46
  double x47;          /// < Estado de la señal en el nodo 47
  double x49;          /// < Estado de la señal en el nodo 49
  double g_0_11;       /// < Ganancia de x0 a x11
  double d_0_15[15];   /// < Buffer de retardo de x0 a x15 (tamaño: 15)
  int    pos_d_0_15;   /// < Posición actual del retardo de x0 a x15
  double g_0_16;       /// < Ganancia de x0 a x16
  double g_0_29;       /// < Ganancia de x0 a x29
  double g_0_30;       /// < Ganancia de x0 a x30
  double d_0_41[16];   /// < Buffer de retardo de x0 a x41 (tamaño: 16)
  int    pos_d_0_41;   /// < Posición actual del retardo de x0 a x41
  double g_0_43;       /// < Ganancia de x0 a x43
  double g_0_44;       /// < Ganancia de x0 a x44
  double g_0_46;       /// < Ganancia de x0 a x46
  double g_0_47;       /// < Ganancia de x0 a x47
  double g_0_49;       /// < Ganancia de x0 a x49
  double g_8_29;       /// < Ganancia de x8 a x29
  double g_9_30;       /// < Ganancia de x9 a x30
  double d_9_46[6];    /// < Buffer de retardo de x9 a x46 (tamaño: 6)
  int    pos_d_9_46;   /// < Posición actual del retardo de x9 a x46
  double g_11_16;      /// < Ganancia de x11 a x16
  double d_11_18[4];   /// < Buffer de retardo de x11 a x18 (tamaño: 4)
  int    pos_d_11_18;  /// < Posición actual del retardo de x11 a x18
  double g_11_24;      /// < Ganancia de x11 a x24
  double g_11_45;      /// < Ganancia de x11 a x45
  double g_15_37;      /// < Ganancia de x15 a x37
  double g_15_49;      /// < Ganancia de x15 a x49
  double d_16_0[2];    /// < Buffer de retardo de x16 a x0 (tamaño: 2)
  int    pos_d_16_0;   /// < Posición actual del retardo de x16 a x0
  double d_16_8[9];    /// < Buffer de retardo de x16 a x8 (tamaño: 9)
  int    pos_d_16_8;   /// < Posición actual del retardo de x16 a x8
  double d_16_11[7];   /// < Buffer de retardo de x16 a x11 (tamaño: 7)
  int    pos_d_16_11;  /// < Posición actual del retardo de x16 a x11
  double d_16_30[8];   /// < Buffer de retardo de x16 a x30 (tamaño: 8)
  int    pos_d_16_30;  /// < Posición actual del retardo de x16 a x30
  double d_16_33[2];   /// < Buffer de retardo de x16 a x33 (tamaño: 2)
  int    pos_d_16_33;  /// < Posición actual del retardo de x16 a x33
  double d_16_37[9];   /// < Buffer de retardo de x16 a x37 (tamaño: 9)
  int    pos_d_16_37;  /// < Posición actual del retardo de x16 a x37
  double g_18_29;      /// < Ganancia de x18 a x29
  double g_18_33;      /// < Ganancia de x18 a x33
  double g_18_37;      /// < Ganancia de x18 a x37
  double g_18_41;      /// < Ganancia de x18 a x41
  double g_21_30;      /// < Ganancia de x21 a x30
  double d_21_44[2];   /// < Buffer de retardo de x21 a x44 (tamaño: 2)
  int    pos_d_21_44;  /// < Posición actual del retardo de x21 a x44
  double g_22_24;      /// < Ganancia de x22 a x24
  double g_22_42;      /// < Ganancia de x22 a x42
  double g_22_45;      /// < Ganancia de x22 a x45
  double g_22_49;      /// < Ganancia de x22 a x49
  double g_23_29;      /// < Ganancia de x23 a x29
  double g_23_38;      /// < Ganancia de x23 a x38
  double g_23_43;      /// < Ganancia de x23 a x43
  double d_24_11[1];   /// < Buffer de retardo de x24 a x11 (tamaño: 1)
  int    pos_d_24_11;  /// < Posición actual del retardo de x24 a x11
  double d_24_42[13];  /// < Buffer de retardo de x24 a x42 (tamaño: 13)
  int    pos_d_24_42;  /// < Posición actual del retardo de x24 a x42
  double d_24_43[20];  /// < Buffer de retardo de x24 a x43 (tamaño: 20)
  int    pos_d_24_43;  /// < Posición actual del retardo de x24 a x43
  double d_29_8[6];    /// < Buffer de retardo de x29 a x8 (tamaño: 6)
  int    pos_d_29_8;   /// < Posición actual del retardo de x29 a x8
  double d_29_15[2];   /// < Buffer de retardo de x29 a x15 (tamaño: 2)
  int    pos_d_29_15;  /// < Posición actual del retardo de x29 a x15
  double d_29_18[4];   /// < Buffer de retardo de x29 a x18 (tamaño: 4)
  int    pos_d_29_18;  /// < Posición actual del retardo de x29 a x18
  double d_30_9[13];   /// < Buffer de retardo de x30 a x9 (tamaño: 13)
  int    pos_d_30_9;   /// < Posición actual del retardo de x30 a x9
  double d_30_11[3];   /// < Buffer de retardo de x30 a x11 (tamaño: 3)
  int    pos_d_30_11;  /// < Posición actual del retardo de x30 a x11
  double d_30_21[10];  /// < Buffer de retardo de x30 a x21 (tamaño: 10)
  int    pos_d_30_21;  /// < Posición actual del retardo de x30 a x21
  double g_30_42;      /// < Ganancia de x30 a x42
  double d_33_38[2];   /// < Buffer de retardo de x33 a x38 (tamaño: 2)
  int    pos_d_33_38;  /// < Posición actual del retardo de x33 a x38
  double d_33_47[1];   /// < Buffer de retardo de x33 a x47 (tamaño: 1)
  int    pos_d_33_47;  /// < Posición actual del retardo de x33 a x47
  double d_37_23[3];   /// < Buffer de retardo de x37 a x23 (tamaño: 3)
  int    pos_d_37_23;  /// < Posición actual del retardo de x37 a x23
  double d_37_46[2];   /// < Buffer de retardo de x37 a x46 (tamaño: 2)
  int    pos_d_37_46;  /// < Posición actual del retardo de x37 a x46
  double d_37_47[6];   /// < Buffer de retardo de x37 a x47 (tamaño: 6)
  int    pos_d_37_47;  /// < Posición actual del retardo de x37 a x47
  double g_38_45;      /// < Ganancia de x38 a x45
  double d_41_18[3];   /// < Buffer de retardo de x41 a x18 (tamaño: 3)
  int    pos_d_41_18;  /// < Posición actual del retardo de x41 a x18
  double g_41_49;      /// < Ganancia de x41 a x49
  double d_42_22[1];   /// < Buffer de retardo de x42 a x22 (tamaño: 1)
  int    pos_d_42_22;  /// < Posición actual del retardo de x42 a x22
  double d_43_38[6];   /// < Buffer de retardo de x43 a x38 (tamaño: 6)
  int    pos_d_43_38;  /// < Posición actual del retardo de x43 a x38
  double g_43_45;      /// < Ganancia de x43 a x45
  double d_44_23[3];   /// < Buffer de retardo de x44 a x23 (tamaño: 3)
  int    pos_d_44_23;  /// < Posición actual del retardo de x44 a x23
  double d_44_33[2];   /// < Buffer de retardo de x44 a x33 (tamaño: 2)
  int    pos_d_44_33;  /// < Posición actual del retardo de x44 a x33
  double d_44_41[13];  /// < Buffer de retardo de x44 a x41 (tamaño: 13)
  int    pos_d_44_41;  /// < Posición actual del retardo de x44 a x41
  double d_45_22[6];   /// < Buffer de retardo de x45 a x22 (tamaño: 6)
  int    pos_d_45_22;  /// < Posición actual del retardo de x45 a x22
  double d_45_44[22];  /// < Buffer de retardo de x45 a x44 (tamaño: 22)
  int    pos_d_45_44;  /// < Posición actual del retardo de x45 a x44
  double d_46_23[1];   /// < Buffer de retardo de x46 a x23 (tamaño: 1)
  int    pos_d_46_23;  /// < Posición actual del retardo de x46 a x23
  double d_47_8[6];    /// < Buffer de retardo de x47 a x8 (tamaño: 6)
  int    pos_d_47_8;   /// < Posición actual del retardo de x47 a x8
  double d_49_15[9];   /// < Buffer de retardo de x49 a x15 (tamaño: 9)
  int    pos_d_49_15;  /// < Posición actual del retardo de x49 a x15
  double d_49_22[1];   /// < Buffer de retardo de x49 a x22 (tamaño: 1)
  int    pos_d_49_22;  /// < Posición actual del retardo de x49 a x22
} filter_t;

/**
 * @brief Esta función debe ser llamada antes de comenzar a procesar audio.
 *
 * @param f Puntero a una estructura del filtro generado.
 */
inline void filter_init(filter_t* f) {
  f->x0  = 0.0f;
  f->x8  = 0.0f;
  f->x9  = 0.0f;
  f->x11 = 0.0f;
  f->x15 = 0.0f;
  f->x16 = 0.0f;
  f->x18 = 0.0f;
  f->x21 = 0.0f;
  f->x22 = 0.0f;
  f->x23 = 0.0f;
  f->x24 = 0.0f;
  f->x29 = 0.0f;
  f->x30 = 0.0f;
  f->x33 = 0.0f;
  f->x37 = 0.0f;
  f->x38 = 0.0f;
  f->x41 = 0.0f;
  f->x42 = 0.0f;
  f->x43 = 0.0f;
  f->x44 = 0.0f;
  f->x45 = 0.0f;
  f->x46 = 0.0f;
  f->x47 = 0.0f;
  f->x49 = 0.0f;

  // Inicialización de retardos
  f->g_0_11 = 1.674714838490945e-01;
  for (int k = 0; k < 15; k++)
    f->d_0_15[k] = 0.0f;
  f->pos_d_0_15 = 0;
  f->g_0_16     = -9.756343530204095e-03;
  f->g_0_29     = 3.501111600304643e-02;
  f->g_0_30     = 1.077138692103189e-01;
  for (int k = 0; k < 16; k++)
    f->d_0_41[k] = 0.0f;
  f->pos_d_0_41 = 0;
  f->g_0_43     = 5.814095004101139e-01;
  f->g_0_44     = -3.073709776684919e-01;
  f->g_0_46     = 9.050847635502615e-01;
  f->g_0_47     = 2.962411138893298e-01;
  f->g_0_49     = 8.874065040535794e-05;
  f->g_8_29     = -3.023709086911396e-01;
  f->g_9_30     = -2.659863048408679e-02;
  for (int k = 0; k < 6; k++)
    f->d_9_46[k] = 0.0f;
  f->pos_d_9_46 = 0;
  f->g_11_16    = -4.429952236909829e-02;
  for (int k = 0; k < 4; k++)
    f->d_11_18[k] = 0.0f;
  f->pos_d_11_18 = 0;
  f->g_11_24     = 8.381735919036956e-02;
  f->g_11_45     = -1.797249230556924e-03;
  f->g_15_37     = 7.769210240661495e-02;
  f->g_15_49     = 5.723871604649096e-03;
  for (int k = 0; k < 2; k++)
    f->d_16_0[k] = 0.0f;
  f->pos_d_16_0 = 0;
  for (int k = 0; k < 9; k++)
    f->d_16_8[k] = 0.0f;
  f->pos_d_16_8 = 0;
  for (int k = 0; k < 7; k++)
    f->d_16_11[k] = 0.0f;
  f->pos_d_16_11 = 0;
  for (int k = 0; k < 8; k++)
    f->d_16_30[k] = 0.0f;
  f->pos_d_16_30 = 0;
  for (int k = 0; k < 2; k++)
    f->d_16_33[k] = 0.0f;
  f->pos_d_16_33 = 0;
  for (int k = 0; k < 9; k++)
    f->d_16_37[k] = 0.0f;
  f->pos_d_16_37 = 0;
  f->g_18_29     = 1.939793454704970e-01;
  f->g_18_33     = -4.357558183742829e-02;
  f->g_18_37     = 2.514019988340071e-02;
  f->g_18_41     = -3.313666877801821e-01;
  f->g_21_30     = 5.497952843401188e-02;
  for (int k = 0; k < 2; k++)
    f->d_21_44[k] = 0.0f;
  f->pos_d_21_44 = 0;
  f->g_22_24     = 3.551544989798064e-02;
  f->g_22_42     = -3.188438844323097e-01;
  f->g_22_45     = -2.325586896115359e-02;
  f->g_22_49     = 5.143689988761104e-01;
  f->g_23_29     = -5.862593021828919e-02;
  f->g_23_38     = -4.938101323567504e-02;
  f->g_23_43     = -6.969016075969775e-02;
  for (int k = 0; k < 1; k++)
    f->d_24_11[k] = 0.0f;
  f->pos_d_24_11 = 0;
  for (int k = 0; k < 13; k++)
    f->d_24_42[k] = 0.0f;
  f->pos_d_24_42 = 0;
  for (int k = 0; k < 20; k++)
    f->d_24_43[k] = 0.0f;
  f->pos_d_24_43 = 0;
  for (int k = 0; k < 6; k++)
    f->d_29_8[k] = 0.0f;
  f->pos_d_29_8 = 0;
  for (int k = 0; k < 2; k++)
    f->d_29_15[k] = 0.0f;
  f->pos_d_29_15 = 0;
  for (int k = 0; k < 4; k++)
    f->d_29_18[k] = 0.0f;
  f->pos_d_29_18 = 0;
  for (int k = 0; k < 13; k++)
    f->d_30_9[k] = 0.0f;
  f->pos_d_30_9 = 0;
  for (int k = 0; k < 3; k++)
    f->d_30_11[k] = 0.0f;
  f->pos_d_30_11 = 0;
  for (int k = 0; k < 10; k++)
    f->d_30_21[k] = 0.0f;
  f->pos_d_30_21 = 0;
  f->g_30_42     = 8.709954354277847e-03;
  for (int k = 0; k < 2; k++)
    f->d_33_38[k] = 0.0f;
  f->pos_d_33_38 = 0;
  for (int k = 0; k < 1; k++)
    f->d_33_47[k] = 0.0f;
  f->pos_d_33_47 = 0;
  for (int k = 0; k < 3; k++)
    f->d_37_23[k] = 0.0f;
  f->pos_d_37_23 = 0;
  for (int k = 0; k < 2; k++)
    f->d_37_46[k] = 0.0f;
  f->pos_d_37_46 = 0;
  for (int k = 0; k < 6; k++)
    f->d_37_47[k] = 0.0f;
  f->pos_d_37_47 = 0;
  f->g_38_45     = -4.087244714068356e-03;
  for (int k = 0; k < 3; k++)
    f->d_41_18[k] = 0.0f;
  f->pos_d_41_18 = 0;
  f->g_41_49     = 5.380415370238348e-03;
  for (int k = 0; k < 1; k++)
    f->d_42_22[k] = 0.0f;
  f->pos_d_42_22 = 0;
  for (int k = 0; k < 6; k++)
    f->d_43_38[k] = 0.0f;
  f->pos_d_43_38 = 0;
  f->g_43_45     = 1.280536327002600e-03;
  for (int k = 0; k < 3; k++)
    f->d_44_23[k] = 0.0f;
  f->pos_d_44_23 = 0;
  for (int k = 0; k < 2; k++)
    f->d_44_33[k] = 0.0f;
  f->pos_d_44_33 = 0;
  for (int k = 0; k < 13; k++)
    f->d_44_41[k] = 0.0f;
  f->pos_d_44_41 = 0;
  for (int k = 0; k < 6; k++)
    f->d_45_22[k] = 0.0f;
  f->pos_d_45_22 = 0;
  for (int k = 0; k < 22; k++)
    f->d_45_44[k] = 0.0f;
  f->pos_d_45_44 = 0;
  for (int k = 0; k < 1; k++)
    f->d_46_23[k] = 0.0f;
  f->pos_d_46_23 = 0;
  for (int k = 0; k < 6; k++)
    f->d_47_8[k] = 0.0f;
  f->pos_d_47_8 = 0;
  for (int k = 0; k < 9; k++)
    f->d_49_15[k] = 0.0f;
  f->pos_d_49_15 = 0;
  for (int k = 0; k < 1; k++)
    f->d_49_22[k] = 0.0f;
  f->pos_d_49_22 = 0;
}

/**
 * @brief Esta función resetea el estado del filtro, incluyendo sus buffers de retardo y sus variables de estado.
 *
 * @param f Puntero a una estructura del filtro generado.
 */
inline void filter_reset(filter_t* f) {
  f->x0  = 0.0f;
  f->x8  = 0.0f;
  f->x9  = 0.0f;
  f->x11 = 0.0f;
  f->x15 = 0.0f;
  f->x16 = 0.0f;
  f->x18 = 0.0f;
  f->x21 = 0.0f;
  f->x22 = 0.0f;
  f->x23 = 0.0f;
  f->x24 = 0.0f;
  f->x29 = 0.0f;
  f->x30 = 0.0f;
  f->x33 = 0.0f;
  f->x37 = 0.0f;
  f->x38 = 0.0f;
  f->x41 = 0.0f;
  f->x42 = 0.0f;
  f->x43 = 0.0f;
  f->x44 = 0.0f;
  f->x45 = 0.0f;
  f->x46 = 0.0f;
  f->x47 = 0.0f;
  f->x49 = 0.0f;
  for (int k = 0; k < 15; k++)
    f->d_0_15[k] = 0.0f;
  f->pos_d_0_15 = 0;
  for (int k = 0; k < 16; k++)
    f->d_0_41[k] = 0.0f;
  f->pos_d_0_41 = 0;
  for (int k = 0; k < 6; k++)
    f->d_9_46[k] = 0.0f;
  f->pos_d_9_46 = 0;
  for (int k = 0; k < 4; k++)
    f->d_11_18[k] = 0.0f;
  f->pos_d_11_18 = 0;
  for (int k = 0; k < 2; k++)
    f->d_16_0[k] = 0.0f;
  f->pos_d_16_0 = 0;
  for (int k = 0; k < 9; k++)
    f->d_16_8[k] = 0.0f;
  f->pos_d_16_8 = 0;
  for (int k = 0; k < 7; k++)
    f->d_16_11[k] = 0.0f;
  f->pos_d_16_11 = 0;
  for (int k = 0; k < 8; k++)
    f->d_16_30[k] = 0.0f;
  f->pos_d_16_30 = 0;
  for (int k = 0; k < 2; k++)
    f->d_16_33[k] = 0.0f;
  f->pos_d_16_33 = 0;
  for (int k = 0; k < 9; k++)
    f->d_16_37[k] = 0.0f;
  f->pos_d_16_37 = 0;
  for (int k = 0; k < 2; k++)
    f->d_21_44[k] = 0.0f;
  f->pos_d_21_44 = 0;
  for (int k = 0; k < 1; k++)
    f->d_24_11[k] = 0.0f;
  f->pos_d_24_11 = 0;
  for (int k = 0; k < 13; k++)
    f->d_24_42[k] = 0.0f;
  f->pos_d_24_42 = 0;
  for (int k = 0; k < 20; k++)
    f->d_24_43[k] = 0.0f;
  f->pos_d_24_43 = 0;
  for (int k = 0; k < 6; k++)
    f->d_29_8[k] = 0.0f;
  f->pos_d_29_8 = 0;
  for (int k = 0; k < 2; k++)
    f->d_29_15[k] = 0.0f;
  f->pos_d_29_15 = 0;
  for (int k = 0; k < 4; k++)
    f->d_29_18[k] = 0.0f;
  f->pos_d_29_18 = 0;
  for (int k = 0; k < 13; k++)
    f->d_30_9[k] = 0.0f;
  f->pos_d_30_9 = 0;
  for (int k = 0; k < 3; k++)
    f->d_30_11[k] = 0.0f;
  f->pos_d_30_11 = 0;
  for (int k = 0; k < 10; k++)
    f->d_30_21[k] = 0.0f;
  f->pos_d_30_21 = 0;
  for (int k = 0; k < 2; k++)
    f->d_33_38[k] = 0.0f;
  f->pos_d_33_38 = 0;
  for (int k = 0; k < 1; k++)
    f->d_33_47[k] = 0.0f;
  f->pos_d_33_47 = 0;
  for (int k = 0; k < 3; k++)
    f->d_37_23[k] = 0.0f;
  f->pos_d_37_23 = 0;
  for (int k = 0; k < 2; k++)
    f->d_37_46[k] = 0.0f;
  f->pos_d_37_46 = 0;
  for (int k = 0; k < 6; k++)
    f->d_37_47[k] = 0.0f;
  f->pos_d_37_47 = 0;
  for (int k = 0; k < 3; k++)
    f->d_41_18[k] = 0.0f;
  f->pos_d_41_18 = 0;
  for (int k = 0; k < 1; k++)
    f->d_42_22[k] = 0.0f;
  f->pos_d_42_22 = 0;
  for (int k = 0; k < 6; k++)
    f->d_43_38[k] = 0.0f;
  f->pos_d_43_38 = 0;
  for (int k = 0; k < 3; k++)
    f->d_44_23[k] = 0.0f;
  f->pos_d_44_23 = 0;
  for (int k = 0; k < 2; k++)
    f->d_44_33[k] = 0.0f;
  f->pos_d_44_33 = 0;
  for (int k = 0; k < 13; k++)
    f->d_44_41[k] = 0.0f;
  f->pos_d_44_41 = 0;
  for (int k = 0; k < 6; k++)
    f->d_45_22[k] = 0.0f;
  f->pos_d_45_22 = 0;
  for (int k = 0; k < 22; k++)
    f->d_45_44[k] = 0.0f;
  f->pos_d_45_44 = 0;
  for (int k = 0; k < 1; k++)
    f->d_46_23[k] = 0.0f;
  f->pos_d_46_23 = 0;
  for (int k = 0; k < 6; k++)
    f->d_47_8[k] = 0.0f;
  f->pos_d_47_8 = 0;
  for (int k = 0; k < 9; k++)
    f->d_49_15[k] = 0.0f;
  f->pos_d_49_15 = 0;
  for (int k = 0; k < 1; k++)
    f->d_49_22[k] = 0.0f;
  f->pos_d_49_22 = 0;
}

/**
 * @brief Procesa una señal de audio mediante el filtro generado.
 *
 * @param f Puntero a una estructura del filtro generado.
 * @param input Puntero a la señal de entrada. Debe tener al menos `num_samples` muestras.
 * @param output Puntero a la señal de salida. Debe tener al menos `num_samples` muestras.
 * @param num_samples Número de muestras a procesar.
 */
inline void filter_process(filter_t* f, const float* input, float* output, int num_samples) {
  for (int n = 0; n < num_samples; n++) {
    // x0
    f->x0 = input[n] + f->d_16_0[f->pos_d_16_0];

    // x8
    f->x8 = 0.0f + f->d_16_8[f->pos_d_16_8] + f->d_29_8[f->pos_d_29_8] + f->d_47_8[f->pos_d_47_8];

    // x9
    f->x9 = 0.0f + f->d_30_9[f->pos_d_30_9];

    // x11
    f->x11 = 0.0f + f->d_16_11[f->pos_d_16_11] + f->d_24_11[f->pos_d_24_11] + f->d_30_11[f->pos_d_30_11];
    f->x11 += f->g_0_11 * f->x0;

    // x15
    f->x15 = 0.0f + f->d_0_15[f->pos_d_0_15] + f->d_29_15[f->pos_d_29_15] + f->d_49_15[f->pos_d_49_15];

    // x16
    f->x16 = 0.0f;
    f->x16 += f->g_0_16 * f->x0;
    f->x16 += f->g_11_16 * f->x11;

    // x18
    f->x18 = 0.0f + f->d_11_18[f->pos_d_11_18] + f->d_29_18[f->pos_d_29_18] + f->d_41_18[f->pos_d_41_18];

    // x21
    f->x21 = 0.0f + f->d_30_21[f->pos_d_30_21];

    // x22
    f->x22 = 0.0f + f->d_42_22[f->pos_d_42_22] + f->d_45_22[f->pos_d_45_22] + f->d_49_22[f->pos_d_49_22];

    // x23
    f->x23 = 0.0f + f->d_37_23[f->pos_d_37_23] + f->d_44_23[f->pos_d_44_23] + f->d_46_23[f->pos_d_46_23];

    // x24
    f->x24 = 0.0f;
    f->x24 += f->g_11_24 * f->x11;
    f->x24 += f->g_22_24 * f->x22;

    // x29
    f->x29 = 0.0f;
    f->x29 += f->g_0_29 * f->x0;
    f->x29 += f->g_8_29 * f->x8;
    f->x29 += f->g_18_29 * f->x18;
    f->x29 += f->g_23_29 * f->x23;

    // x30
    f->x30 = 0.0f + f->d_16_30[f->pos_d_16_30];
    f->x30 += f->g_0_30 * f->x0;
    f->x30 += f->g_9_30 * f->x9;
    f->x30 += f->g_21_30 * f->x21;

    // x33
    f->x33 = 0.0f + f->d_16_33[f->pos_d_16_33] + f->d_44_33[f->pos_d_44_33];
    f->x33 += f->g_18_33 * f->x18;

    // x37
    f->x37 = 0.0f + f->d_16_37[f->pos_d_16_37];
    f->x37 += f->g_15_37 * f->x15;
    f->x37 += f->g_18_37 * f->x18;

    // x38
    f->x38 = 0.0f + f->d_33_38[f->pos_d_33_38] + f->d_43_38[f->pos_d_43_38];
    f->x38 += f->g_23_38 * f->x23;

    // x41
    f->x41 = 0.0f + f->d_0_41[f->pos_d_0_41] + f->d_44_41[f->pos_d_44_41];
    f->x41 += f->g_18_41 * f->x18;

    // x42
    f->x42 = 0.0f + f->d_24_42[f->pos_d_24_42];
    f->x42 += f->g_22_42 * f->x22;
    f->x42 += f->g_30_42 * f->x30;

    // x43
    f->x43 = 0.0f + f->d_24_43[f->pos_d_24_43];
    f->x43 += f->g_0_43 * f->x0;
    f->x43 += f->g_23_43 * f->x23;

    // x44
    f->x44 = 0.0f + f->d_21_44[f->pos_d_21_44] + f->d_45_44[f->pos_d_45_44];
    f->x44 += f->g_0_44 * f->x0;

    // x45
    f->x45 = 0.0f;
    f->x45 += f->g_11_45 * f->x11;
    f->x45 += f->g_22_45 * f->x22;
    f->x45 += f->g_38_45 * f->x38;
    f->x45 += f->g_43_45 * f->x43;

    // x46
    f->x46 = 0.0f + f->d_9_46[f->pos_d_9_46] + f->d_37_46[f->pos_d_37_46];
    f->x46 += f->g_0_46 * f->x0;

    // x47
    f->x47 = 0.0f + f->d_33_47[f->pos_d_33_47] + f->d_37_47[f->pos_d_37_47];
    f->x47 += f->g_0_47 * f->x0;

    // x49
    f->x49 = 0.0f;
    f->x49 += f->g_0_49 * f->x0;
    f->x49 += f->g_15_49 * f->x15;
    f->x49 += f->g_22_49 * f->x22;
    f->x49 += f->g_41_49 * f->x41;

    // Actualización de retardos
    f->d_0_15[f->pos_d_0_15]   = f->x0;
    f->pos_d_0_15              = (f->pos_d_0_15 + 1) % 15;
    f->d_0_41[f->pos_d_0_41]   = f->x0;
    f->pos_d_0_41              = (f->pos_d_0_41 + 1) % 16;
    f->d_9_46[f->pos_d_9_46]   = f->x9;
    f->pos_d_9_46              = (f->pos_d_9_46 + 1) % 6;
    f->d_11_18[f->pos_d_11_18] = f->x11;
    f->pos_d_11_18             = (f->pos_d_11_18 + 1) % 4;
    f->d_16_0[f->pos_d_16_0]   = f->x16;
    f->pos_d_16_0              = (f->pos_d_16_0 + 1) % 2;
    f->d_16_8[f->pos_d_16_8]   = f->x16;
    f->pos_d_16_8              = (f->pos_d_16_8 + 1) % 9;
    f->d_16_11[f->pos_d_16_11] = f->x16;
    f->pos_d_16_11             = (f->pos_d_16_11 + 1) % 7;
    f->d_16_30[f->pos_d_16_30] = f->x16;
    f->pos_d_16_30             = (f->pos_d_16_30 + 1) % 8;
    f->d_16_33[f->pos_d_16_33] = f->x16;
    f->pos_d_16_33             = (f->pos_d_16_33 + 1) % 2;
    f->d_16_37[f->pos_d_16_37] = f->x16;
    f->pos_d_16_37             = (f->pos_d_16_37 + 1) % 9;
    f->d_21_44[f->pos_d_21_44] = f->x21;
    f->pos_d_21_44             = (f->pos_d_21_44 + 1) % 2;
    f->d_24_11[f->pos_d_24_11] = f->x24;
    f->pos_d_24_11             = (f->pos_d_24_11 + 1) % 1;
    f->d_24_42[f->pos_d_24_42] = f->x24;
    f->pos_d_24_42             = (f->pos_d_24_42 + 1) % 13;
    f->d_24_43[f->pos_d_24_43] = f->x24;
    f->pos_d_24_43             = (f->pos_d_24_43 + 1) % 20;
    f->d_29_8[f->pos_d_29_8]   = f->x29;
    f->pos_d_29_8              = (f->pos_d_29_8 + 1) % 6;
    f->d_29_15[f->pos_d_29_15] = f->x29;
    f->pos_d_29_15             = (f->pos_d_29_15 + 1) % 2;
    f->d_29_18[f->pos_d_29_18] = f->x29;
    f->pos_d_29_18             = (f->pos_d_29_18 + 1) % 4;
    f->d_30_9[f->pos_d_30_9]   = f->x30;
    f->pos_d_30_9              = (f->pos_d_30_9 + 1) % 13;
    f->d_30_11[f->pos_d_30_11] = f->x30;
    f->pos_d_30_11             = (f->pos_d_30_11 + 1) % 3;
    f->d_30_21[f->pos_d_30_21] = f->x30;
    f->pos_d_30_21             = (f->pos_d_30_21 + 1) % 10;
    f->d_33_38[f->pos_d_33_38] = f->x33;
    f->pos_d_33_38             = (f->pos_d_33_38 + 1) % 2;
    f->d_33_47[f->pos_d_33_47] = f->x33;
    f->pos_d_33_47             = (f->pos_d_33_47 + 1) % 1;
    f->d_37_23[f->pos_d_37_23] = f->x37;
    f->pos_d_37_23             = (f->pos_d_37_23 + 1) % 3;
    f->d_37_46[f->pos_d_37_46] = f->x37;
    f->pos_d_37_46             = (f->pos_d_37_46 + 1) % 2;
    f->d_37_47[f->pos_d_37_47] = f->x37;
    f->pos_d_37_47             = (f->pos_d_37_47 + 1) % 6;
    f->d_41_18[f->pos_d_41_18] = f->x41;
    f->pos_d_41_18             = (f->pos_d_41_18 + 1) % 3;
    f->d_42_22[f->pos_d_42_22] = f->x42;
    f->pos_d_42_22             = (f->pos_d_42_22 + 1) % 1;
    f->d_43_38[f->pos_d_43_38] = f->x43;
    f->pos_d_43_38             = (f->pos_d_43_38 + 1) % 6;
    f->d_44_23[f->pos_d_44_23] = f->x44;
    f->pos_d_44_23             = (f->pos_d_44_23 + 1) % 3;
    f->d_44_33[f->pos_d_44_33] = f->x44;
    f->pos_d_44_33             = (f->pos_d_44_33 + 1) % 2;
    f->d_44_41[f->pos_d_44_41] = f->x44;
    f->pos_d_44_41             = (f->pos_d_44_41 + 1) % 13;
    f->d_45_22[f->pos_d_45_22] = f->x45;
    f->pos_d_45_22             = (f->pos_d_45_22 + 1) % 6;
    f->d_45_44[f->pos_d_45_44] = f->x45;
    f->pos_d_45_44             = (f->pos_d_45_44 + 1) % 22;
    f->d_46_23[f->pos_d_46_23] = f->x46;
    f->pos_d_46_23             = (f->pos_d_46_23 + 1) % 1;
    f->d_47_8[f->pos_d_47_8]   = f->x47;
    f->pos_d_47_8              = (f->pos_d_47_8 + 1) % 6;
    f->d_49_15[f->pos_d_49_15] = f->x49;
    f->pos_d_49_15             = (f->pos_d_49_15 + 1) % 9;
    f->d_49_22[f->pos_d_49_22] = f->x49;
    f->pos_d_49_22             = (f->pos_d_49_22 + 1) % 1;
    output[n]                  = f->x49;
  }
}

#ifdef __cplusplus
}  // __cplusplus
#endif
