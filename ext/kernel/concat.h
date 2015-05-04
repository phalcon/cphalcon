
#ifndef ZEPHIR_KERNEL_CONCAT_H
#define ZEPHIR_KERNEL_CONCAT_H

#include <php.h>
#include <Zend/zend.h>

#include "kernel/main.h"

#define ZEPHIR_CONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(&result, op1, sizeof(op1)-1, op2, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(&result, op1, sizeof(op1)-1, op2, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVSV(result, op1, op2, op3, op4) \
	 zephir_concat_svsv(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVSV(result, op1, op2, op3, op4) \
	 zephir_concat_svsv(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVSVSSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10) \
	 zephir_concat_svsvssvsvs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, op9, op10, sizeof(op10)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVSVSSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10) \
	 zephir_concat_svsvssvsvs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, op9, op10, sizeof(op10)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVSVSV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_svsvsv(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVSVSV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_svsvsv(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVSVSVS(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvsvs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVSVSVS(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvsvs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVSVSVSV(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_svsvsvsv(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVSVSVSV(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_svsvsvsv(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVSVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9) \
	 zephir_concat_svsvsvsvs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, op9, sizeof(op9)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVSVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9) \
	 zephir_concat_svsvsvsvs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, op9, sizeof(op9)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVSVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvv(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVSVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvv(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVSVVSV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvvsv(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, op6, sizeof(op6)-1, op7, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVSVVSV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvvsv(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, op6, sizeof(op6)-1, op7, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVV(result, op1, op2, op3) \
	 zephir_concat_svv(&result, op1, sizeof(op1)-1, op2, op3, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVV(result, op1, op2, op3) \
	 zephir_concat_svv(&result, op1, sizeof(op1)-1, op2, op3, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVVS(result, op1, op2, op3, op4) \
	 zephir_concat_svvs(&result, op1, sizeof(op1)-1, op2, op3, op4, sizeof(op4)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVVS(result, op1, op2, op3, op4) \
	 zephir_concat_svvs(&result, op1, sizeof(op1)-1, op2, op3, op4, sizeof(op4)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(&result, op1, op2, sizeof(op2)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(&result, op1, op2, sizeof(op2)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VSV(result, op1, op2, op3) \
	 zephir_concat_vsv(&result, op1, op2, sizeof(op2)-1, op3, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VSV(result, op1, op2, op3) \
	 zephir_concat_vsv(&result, op1, op2, sizeof(op2)-1, op3, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VSVS(result, op1, op2, op3, op4) \
	 zephir_concat_vsvs(&result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VSVS(result, op1, op2, op3, op4) \
	 zephir_concat_vsvs(&result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VSVSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vsvsv(&result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VSVSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vsvsv(&result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VSVSVS(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vsvsvs(&result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VSVSVS(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vsvsvs(&result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VSVSVSV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_vsvsvsv(&result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VSVSVSV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_vsvsvsv(&result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VSVV(result, op1, op2, op3, op4) \
	 zephir_concat_vsvv(&result, op1, op2, sizeof(op2)-1, op3, op4, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VSVV(result, op1, op2, op3, op4) \
	 zephir_concat_vsvv(&result, op1, op2, sizeof(op2)-1, op3, op4, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(&result, op1, op2, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(&result, op1, op2, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VVS(result, op1, op2, op3) \
	 zephir_concat_vvs(&result, op1, op2, op3, sizeof(op3)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VVS(result, op1, op2, op3) \
	 zephir_concat_vvs(&result, op1, op2, op3, sizeof(op3)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VVSV(result, op1, op2, op3, op4) \
	 zephir_concat_vvsv(&result, op1, op2, op3, sizeof(op3)-1, op4, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VVSV(result, op1, op2, op3, op4) \
	 zephir_concat_vvsv(&result, op1, op2, op3, sizeof(op3)-1, op4, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VVV(result, op1, op2, op3) \
	 zephir_concat_vvv(&result, op1, op2, op3, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VVV(result, op1, op2, op3) \
	 zephir_concat_vvv(&result, op1, op2, op3, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VVVV(result, op1, op2, op3, op4) \
	 zephir_concat_vvvv(&result, op1, op2, op3, op4, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VVVV(result, op1, op2, op3, op4) \
	 zephir_concat_vvvv(&result, op1, op2, op3, op4, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VVVVSVV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_vvvvsvv(&result, op1, op2, op3, op4, op5, sizeof(op5)-1, op6, op7, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VVVVSVV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_vvvvsvv(&result, op1, op2, op3, op4, op5, sizeof(op5)-1, op6, op7, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VVVVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vvvvv(&result, op1, op2, op3, op4, op5, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VVVVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vvvvv(&result, op1, op2, op3, op4, op5, 1 TSRMLS_CC);


void zephir_concat_sv(zval **result, const char *op1, zend_uint op1_len, zval *op2, int self_var TSRMLS_DC);
void zephir_concat_svs(zval **result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, int self_var TSRMLS_DC);
void zephir_concat_svsv(zval **result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, int self_var TSRMLS_DC);
void zephir_concat_svsvs(zval **result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, const char *op5, zend_uint op5_len, int self_var TSRMLS_DC);
void zephir_concat_svsvssvsvs(zval **result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, const char *op5, zend_uint op5_len, const char *op6, zend_uint op6_len, zval *op7, const char *op8, zend_uint op8_len, zval *op9, const char *op10, zend_uint op10_len, int self_var TSRMLS_DC);
void zephir_concat_svsvsv(zval **result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, const char *op5, zend_uint op5_len, zval *op6, int self_var TSRMLS_DC);
void zephir_concat_svsvsvs(zval **result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, const char *op5, zend_uint op5_len, zval *op6, const char *op7, zend_uint op7_len, int self_var TSRMLS_DC);
void zephir_concat_svsvsvsv(zval **result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, const char *op5, zend_uint op5_len, zval *op6, const char *op7, zend_uint op7_len, zval *op8, int self_var TSRMLS_DC);
void zephir_concat_svsvsvsvs(zval **result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, const char *op5, zend_uint op5_len, zval *op6, const char *op7, zend_uint op7_len, zval *op8, const char *op9, zend_uint op9_len, int self_var TSRMLS_DC);
void zephir_concat_svsvv(zval **result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, zval *op5, int self_var TSRMLS_DC);
void zephir_concat_svsvvsv(zval **result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, zval *op5, const char *op6, zend_uint op6_len, zval *op7, int self_var TSRMLS_DC);
void zephir_concat_svv(zval **result, const char *op1, zend_uint op1_len, zval *op2, zval *op3, int self_var TSRMLS_DC);
void zephir_concat_svvs(zval **result, const char *op1, zend_uint op1_len, zval *op2, zval *op3, const char *op4, zend_uint op4_len, int self_var TSRMLS_DC);
void zephir_concat_vs(zval **result, zval *op1, const char *op2, zend_uint op2_len, int self_var TSRMLS_DC);
void zephir_concat_vsv(zval **result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, int self_var TSRMLS_DC);
void zephir_concat_vsvs(zval **result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, int self_var TSRMLS_DC);
void zephir_concat_vsvsv(zval **result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, int self_var TSRMLS_DC);
void zephir_concat_vsvsvs(zval **result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, const char *op6, zend_uint op6_len, int self_var TSRMLS_DC);
void zephir_concat_vsvsvsv(zval **result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, const char *op6, zend_uint op6_len, zval *op7, int self_var TSRMLS_DC);
void zephir_concat_vsvv(zval **result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, zval *op4, int self_var TSRMLS_DC);
void zephir_concat_vv(zval **result, zval *op1, zval *op2, int self_var TSRMLS_DC);
void zephir_concat_vvs(zval **result, zval *op1, zval *op2, const char *op3, zend_uint op3_len, int self_var TSRMLS_DC);
void zephir_concat_vvsv(zval **result, zval *op1, zval *op2, const char *op3, zend_uint op3_len, zval *op4, int self_var TSRMLS_DC);
void zephir_concat_vvv(zval **result, zval *op1, zval *op2, zval *op3, int self_var TSRMLS_DC);
void zephir_concat_vvvv(zval **result, zval *op1, zval *op2, zval *op3, zval *op4, int self_var TSRMLS_DC);
void zephir_concat_vvvvsvv(zval **result, zval *op1, zval *op2, zval *op3, zval *op4, const char *op5, zend_uint op5_len, zval *op6, zval *op7, int self_var TSRMLS_DC);
void zephir_concat_vvvvv(zval **result, zval *op1, zval *op2, zval *op3, zval *op4, zval *op5, int self_var TSRMLS_DC);
void zephir_concat_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);

#endif /* ZEPHIR_KERNEL_CONCAT_H */

