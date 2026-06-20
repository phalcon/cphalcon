
#ifndef ZEPHIR_KERNEL_CONCAT_H
#define ZEPHIR_KERNEL_CONCAT_H
#include <php.h>
#include <Zend/zend.h>
#include "kernel/main.h"
#define ZEPHIR_CONCAT_SS(result, op1, op2) \
	 zephir_concat_ss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, 0);
#define ZEPHIR_SCONCAT_SS(result, op1, op2) \
	 zephir_concat_ss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, 1);

#define ZEPHIR_CONCAT_SSS(result, op1, op2, op3) \
	 zephir_concat_sss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_SSS(result, op1, op2, op3) \
	 zephir_concat_sss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSVSSVSS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10, op11, op12, op13, op14, op15, op16, op17, op18, op19, op20, op21, op22, op23, op24, op25, op26, op27, op28, op29, op30, op31, op32, op33, op34, op35, op36) \
	 zephir_concat_ssssssssssssssssssssssssssssssvssvss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, sizeof(op5)-1, op6, sizeof(op6)-1, op7, sizeof(op7)-1, op8, sizeof(op8)-1, op9, sizeof(op9)-1, op10, sizeof(op10)-1, op11, sizeof(op11)-1, op12, sizeof(op12)-1, op13, sizeof(op13)-1, op14, sizeof(op14)-1, op15, sizeof(op15)-1, op16, sizeof(op16)-1, op17, sizeof(op17)-1, op18, sizeof(op18)-1, op19, sizeof(op19)-1, op20, sizeof(op20)-1, op21, sizeof(op21)-1, op22, sizeof(op22)-1, op23, sizeof(op23)-1, op24, sizeof(op24)-1, op25, sizeof(op25)-1, op26, sizeof(op26)-1, op27, sizeof(op27)-1, op28, sizeof(op28)-1, op29, sizeof(op29)-1, op30, sizeof(op30)-1, op31, op32, sizeof(op32)-1, op33, sizeof(op33)-1, op34, op35, sizeof(op35)-1, op36, sizeof(op36)-1, 0);
#define ZEPHIR_SCONCAT_SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSVSSVSS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10, op11, op12, op13, op14, op15, op16, op17, op18, op19, op20, op21, op22, op23, op24, op25, op26, op27, op28, op29, op30, op31, op32, op33, op34, op35, op36) \
	 zephir_concat_ssssssssssssssssssssssssssssssvssvss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, sizeof(op5)-1, op6, sizeof(op6)-1, op7, sizeof(op7)-1, op8, sizeof(op8)-1, op9, sizeof(op9)-1, op10, sizeof(op10)-1, op11, sizeof(op11)-1, op12, sizeof(op12)-1, op13, sizeof(op13)-1, op14, sizeof(op14)-1, op15, sizeof(op15)-1, op16, sizeof(op16)-1, op17, sizeof(op17)-1, op18, sizeof(op18)-1, op19, sizeof(op19)-1, op20, sizeof(op20)-1, op21, sizeof(op21)-1, op22, sizeof(op22)-1, op23, sizeof(op23)-1, op24, sizeof(op24)-1, op25, sizeof(op25)-1, op26, sizeof(op26)-1, op27, sizeof(op27)-1, op28, sizeof(op28)-1, op29, sizeof(op29)-1, op30, sizeof(op30)-1, op31, op32, sizeof(op32)-1, op33, sizeof(op33)-1, op34, op35, sizeof(op35)-1, op36, sizeof(op36)-1, 1);

#define ZEPHIR_CONCAT_SSSSSSSSVSSVSS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10, op11, op12, op13, op14) \
	 zephir_concat_ssssssssvssvss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, sizeof(op5)-1, op6, sizeof(op6)-1, op7, sizeof(op7)-1, op8, sizeof(op8)-1, op9, op10, sizeof(op10)-1, op11, sizeof(op11)-1, op12, op13, sizeof(op13)-1, op14, sizeof(op14)-1, 0);
#define ZEPHIR_SCONCAT_SSSSSSSSVSSVSS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10, op11, op12, op13, op14) \
	 zephir_concat_ssssssssvssvss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, sizeof(op5)-1, op6, sizeof(op6)-1, op7, sizeof(op7)-1, op8, sizeof(op8)-1, op9, op10, sizeof(op10)-1, op11, sizeof(op11)-1, op12, op13, sizeof(op13)-1, op14, sizeof(op14)-1, 1);

#define ZEPHIR_CONCAT_SSSVSVSVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10, op11, op12, op13) \
	 zephir_concat_sssvsvsvsvsvs(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, op9, sizeof(op9)-1, op10, op11, sizeof(op11)-1, op12, op13, sizeof(op13)-1, 0);
#define ZEPHIR_SCONCAT_SSSVSVSVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10, op11, op12, op13) \
	 zephir_concat_sssvsvsvsvsvs(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, op9, sizeof(op9)-1, op10, op11, sizeof(op11)-1, op12, op13, sizeof(op13)-1, 1);

#define ZEPHIR_CONCAT_SSVSVSV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_ssvsvsv(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, 0);
#define ZEPHIR_SCONCAT_SSVSVSV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_ssvsvsv(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, 1);

#define ZEPHIR_CONCAT_SSVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_ssvsvsvs(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, 0);
#define ZEPHIR_SCONCAT_SSVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_ssvsvsvs(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, 1);

#define ZEPHIR_CONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(result, op1, sizeof(op1)-1, op2, 0);
#define ZEPHIR_SCONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(result, op1, sizeof(op1)-1, op2, 1);

#define ZEPHIR_CONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_SVSSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svssv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, 0);
#define ZEPHIR_SCONCAT_SVSSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svssv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, 1);

#define ZEPHIR_CONCAT_SVSSVS(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_svssvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, 0);
#define ZEPHIR_SCONCAT_SVSSVS(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_svssvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, 1);

#define ZEPHIR_CONCAT_SVSSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_svssvsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, 0);
#define ZEPHIR_SCONCAT_SVSSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_svssvsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, 1);

#define ZEPHIR_CONCAT_SVSV(result, op1, op2, op3, op4) \
	 zephir_concat_svsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, 0);
#define ZEPHIR_SCONCAT_SVSV(result, op1, op2, op3, op4) \
	 zephir_concat_svsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, 1);

#define ZEPHIR_CONCAT_SVSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 0);
#define ZEPHIR_SCONCAT_SVSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 1);

#define ZEPHIR_CONCAT_SVSVSSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10) \
	 zephir_concat_svsvssvsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, op9, op10, sizeof(op10)-1, 0);
#define ZEPHIR_SCONCAT_SVSVSSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10) \
	 zephir_concat_svsvssvsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, op9, op10, sizeof(op10)-1, 1);

#define ZEPHIR_CONCAT_SVSVSV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_svsvsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, 0);
#define ZEPHIR_SCONCAT_SVSVSV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_svsvsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, 1);

#define ZEPHIR_CONCAT_SVSVSVS(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, 0);
#define ZEPHIR_SCONCAT_SVSVSVS(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, 1);

#define ZEPHIR_CONCAT_SVSVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9) \
	 zephir_concat_svsvsvsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, op9, sizeof(op9)-1, 0);
#define ZEPHIR_SCONCAT_SVSVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9) \
	 zephir_concat_svsvsvsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, op9, sizeof(op9)-1, 1);

#define ZEPHIR_CONCAT_SVSVSVSVSV(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10) \
	 zephir_concat_svsvsvsvsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, op9, sizeof(op9)-1, op10, 0);
#define ZEPHIR_SCONCAT_SVSVSVSVSV(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10) \
	 zephir_concat_svsvsvsvsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, op9, sizeof(op9)-1, op10, 1);

#define ZEPHIR_CONCAT_SVSVSVV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvsvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, 0);
#define ZEPHIR_SCONCAT_SVSVSVV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvsvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, 1);

#define ZEPHIR_CONCAT_SVSVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, 0);
#define ZEPHIR_SCONCAT_SVSVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, 1);

#define ZEPHIR_CONCAT_SVSVVSV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvvsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, op6, sizeof(op6)-1, op7, 0);
#define ZEPHIR_SCONCAT_SVSVVSV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvvsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, op6, sizeof(op6)-1, op7, 1);

#define ZEPHIR_CONCAT_SVSVVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_svsvvsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, 0);
#define ZEPHIR_SCONCAT_SVSVVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_svsvvsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, 1);

#define ZEPHIR_CONCAT_SVSVVV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_svsvvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, op6, 0);
#define ZEPHIR_SCONCAT_SVSVVV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_svsvvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, op6, 1);

#define ZEPHIR_CONCAT_SVSVVVV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvvvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, op6, op7, 0);
#define ZEPHIR_SCONCAT_SVSVVVV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvvvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, op6, op7, 1);

#define ZEPHIR_CONCAT_SVV(result, op1, op2, op3) \
	 zephir_concat_svv(result, op1, sizeof(op1)-1, op2, op3, 0);
#define ZEPHIR_SCONCAT_SVV(result, op1, op2, op3) \
	 zephir_concat_svv(result, op1, sizeof(op1)-1, op2, op3, 1);

#define ZEPHIR_CONCAT_SVVS(result, op1, op2, op3, op4) \
	 zephir_concat_svvs(result, op1, sizeof(op1)-1, op2, op3, op4, sizeof(op4)-1, 0);
#define ZEPHIR_SCONCAT_SVVS(result, op1, op2, op3, op4) \
	 zephir_concat_svvs(result, op1, sizeof(op1)-1, op2, op3, op4, sizeof(op4)-1, 1);

#define ZEPHIR_CONCAT_SVVVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svvvs(result, op1, sizeof(op1)-1, op2, op3, op4, op5, sizeof(op5)-1, 0);
#define ZEPHIR_SCONCAT_SVVVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svvvs(result, op1, sizeof(op1)-1, op2, op3, op4, op5, sizeof(op5)-1, 1);

#define ZEPHIR_CONCAT_SVVVVVVVVVV(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10, op11) \
	 zephir_concat_svvvvvvvvvv(result, op1, sizeof(op1)-1, op2, op3, op4, op5, op6, op7, op8, op9, op10, op11, 0);
#define ZEPHIR_SCONCAT_SVVVVVVVVVV(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10, op11) \
	 zephir_concat_svvvvvvvvvv(result, op1, sizeof(op1)-1, op2, op3, op4, op5, op6, op7, op8, op9, op10, op11, 1);

#define ZEPHIR_CONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(result, op1, op2, sizeof(op2)-1, 0);
#define ZEPHIR_SCONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(result, op1, op2, sizeof(op2)-1, 1);

#define ZEPHIR_CONCAT_VSV(result, op1, op2, op3) \
	 zephir_concat_vsv(result, op1, op2, sizeof(op2)-1, op3, 0);
#define ZEPHIR_SCONCAT_VSV(result, op1, op2, op3) \
	 zephir_concat_vsv(result, op1, op2, sizeof(op2)-1, op3, 1);

#define ZEPHIR_CONCAT_VSVS(result, op1, op2, op3, op4) \
	 zephir_concat_vsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 0);
#define ZEPHIR_SCONCAT_VSVS(result, op1, op2, op3, op4) \
	 zephir_concat_vsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 1);

#define ZEPHIR_CONCAT_VSVSSV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vsvssv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, sizeof(op5)-1, op6, 0);
#define ZEPHIR_SCONCAT_VSVSSV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vsvssv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, sizeof(op5)-1, op6, 1);

#define ZEPHIR_CONCAT_VSVSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vsvsv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, 0);
#define ZEPHIR_SCONCAT_VSVSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vsvsv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, 1);

#define ZEPHIR_CONCAT_VSVSVS(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vsvsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, 0);
#define ZEPHIR_SCONCAT_VSVSVS(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vsvsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, 1);

#define ZEPHIR_CONCAT_VSVSVSV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_vsvsvsv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, 0);
#define ZEPHIR_SCONCAT_VSVSVSV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_vsvsvsv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, 1);

#define ZEPHIR_CONCAT_VSVSVSVSV(result, op1, op2, op3, op4, op5, op6, op7, op8, op9) \
	 zephir_concat_vsvsvsvsv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, op9, 0);
#define ZEPHIR_SCONCAT_VSVSVSVSV(result, op1, op2, op3, op4, op5, op6, op7, op8, op9) \
	 zephir_concat_vsvsvsvsv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, op9, 1);

#define ZEPHIR_CONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(result, op1, op2, 0);
#define ZEPHIR_SCONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(result, op1, op2, 1);

#define ZEPHIR_CONCAT_VVS(result, op1, op2, op3) \
	 zephir_concat_vvs(result, op1, op2, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_VVS(result, op1, op2, op3) \
	 zephir_concat_vvs(result, op1, op2, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_VVSV(result, op1, op2, op3, op4) \
	 zephir_concat_vvsv(result, op1, op2, op3, sizeof(op3)-1, op4, 0);
#define ZEPHIR_SCONCAT_VVSV(result, op1, op2, op3, op4) \
	 zephir_concat_vvsv(result, op1, op2, op3, sizeof(op3)-1, op4, 1);

#define ZEPHIR_CONCAT_VVV(result, op1, op2, op3) \
	 zephir_concat_vvv(result, op1, op2, op3, 0);
#define ZEPHIR_SCONCAT_VVV(result, op1, op2, op3) \
	 zephir_concat_vvv(result, op1, op2, op3, 1);

#define ZEPHIR_CONCAT_VVVV(result, op1, op2, op3, op4) \
	 zephir_concat_vvvv(result, op1, op2, op3, op4, 0);
#define ZEPHIR_SCONCAT_VVVV(result, op1, op2, op3, op4) \
	 zephir_concat_vvvv(result, op1, op2, op3, op4, 1);

#define ZEPHIR_CONCAT_VVVVSVV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_vvvvsvv(result, op1, op2, op3, op4, op5, sizeof(op5)-1, op6, op7, 0);
#define ZEPHIR_SCONCAT_VVVVSVV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_vvvvsvv(result, op1, op2, op3, op4, op5, sizeof(op5)-1, op6, op7, 1);

#define ZEPHIR_CONCAT_VVVVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vvvvv(result, op1, op2, op3, op4, op5, 0);
#define ZEPHIR_SCONCAT_VVVVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vvvvv(result, op1, op2, op3, op4, op5, 1);


void zephir_concat_ss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, int self_var);
void zephir_concat_sss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, int self_var);
void zephir_concat_ssssssssssssssssssssssssssssssvssvss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, const char *op5, uint32_t op5_len, const char *op6, uint32_t op6_len, const char *op7, uint32_t op7_len, const char *op8, uint32_t op8_len, const char *op9, uint32_t op9_len, const char *op10, uint32_t op10_len, const char *op11, uint32_t op11_len, const char *op12, uint32_t op12_len, const char *op13, uint32_t op13_len, const char *op14, uint32_t op14_len, const char *op15, uint32_t op15_len, const char *op16, uint32_t op16_len, const char *op17, uint32_t op17_len, const char *op18, uint32_t op18_len, const char *op19, uint32_t op19_len, const char *op20, uint32_t op20_len, const char *op21, uint32_t op21_len, const char *op22, uint32_t op22_len, const char *op23, uint32_t op23_len, const char *op24, uint32_t op24_len, const char *op25, uint32_t op25_len, const char *op26, uint32_t op26_len, const char *op27, uint32_t op27_len, const char *op28, uint32_t op28_len, const char *op29, uint32_t op29_len, const char *op30, uint32_t op30_len, zval *op31, const char *op32, uint32_t op32_len, const char *op33, uint32_t op33_len, zval *op34, const char *op35, uint32_t op35_len, const char *op36, uint32_t op36_len, int self_var);
void zephir_concat_ssssssssvssvss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, const char *op5, uint32_t op5_len, const char *op6, uint32_t op6_len, const char *op7, uint32_t op7_len, const char *op8, uint32_t op8_len, zval *op9, const char *op10, uint32_t op10_len, const char *op11, uint32_t op11_len, zval *op12, const char *op13, uint32_t op13_len, const char *op14, uint32_t op14_len, int self_var);
void zephir_concat_sssvsvsvsvsvs(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, zval *op8, const char *op9, uint32_t op9_len, zval *op10, const char *op11, uint32_t op11_len, zval *op12, const char *op13, uint32_t op13_len, int self_var);
void zephir_concat_ssvsvsv(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, zval *op7, int self_var);
void zephir_concat_ssvsvsvs(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, zval *op7, const char *op8, uint32_t op8_len, int self_var);
void zephir_concat_sv(zval *result, const char *op1, uint32_t op1_len, zval *op2, int self_var);
void zephir_concat_svs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, int self_var);
void zephir_concat_svssv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, zval *op5, int self_var);
void zephir_concat_svssvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, int self_var);
void zephir_concat_svssvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, zval *op7, const char *op8, uint32_t op8_len, int self_var);
void zephir_concat_svsv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, int self_var);
void zephir_concat_svsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, int self_var);
void zephir_concat_svsvssvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, const char *op6, uint32_t op6_len, zval *op7, const char *op8, uint32_t op8_len, zval *op9, const char *op10, uint32_t op10_len, int self_var);
void zephir_concat_svsvsv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, int self_var);
void zephir_concat_svsvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, int self_var);
void zephir_concat_svsvsvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, zval *op8, const char *op9, uint32_t op9_len, int self_var);
void zephir_concat_svsvsvsvsv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, zval *op8, const char *op9, uint32_t op9_len, zval *op10, int self_var);
void zephir_concat_svsvsvv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, zval *op7, int self_var);
void zephir_concat_svsvv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, zval *op5, int self_var);
void zephir_concat_svsvvsv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, zval *op5, const char *op6, uint32_t op6_len, zval *op7, int self_var);
void zephir_concat_svsvvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, zval *op5, const char *op6, uint32_t op6_len, zval *op7, const char *op8, uint32_t op8_len, int self_var);
void zephir_concat_svsvvv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, zval *op5, zval *op6, int self_var);
void zephir_concat_svsvvvv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, zval *op5, zval *op6, zval *op7, int self_var);
void zephir_concat_svv(zval *result, const char *op1, uint32_t op1_len, zval *op2, zval *op3, int self_var);
void zephir_concat_svvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, zval *op3, const char *op4, uint32_t op4_len, int self_var);
void zephir_concat_svvvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, zval *op3, zval *op4, const char *op5, uint32_t op5_len, int self_var);
void zephir_concat_svvvvvvvvvv(zval *result, const char *op1, uint32_t op1_len, zval *op2, zval *op3, zval *op4, zval *op5, zval *op6, zval *op7, zval *op8, zval *op9, zval *op10, zval *op11, int self_var);
void zephir_concat_vs(zval *result, zval *op1, const char *op2, uint32_t op2_len, int self_var);
void zephir_concat_vsv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, int self_var);
void zephir_concat_vsvs(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, int self_var);
void zephir_concat_vsvssv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, const char *op5, uint32_t op5_len, zval *op6, int self_var);
void zephir_concat_vsvsv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, int self_var);
void zephir_concat_vsvsvs(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, int self_var);
void zephir_concat_vsvsvsv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, zval *op7, int self_var);
void zephir_concat_vsvsvsvsv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, zval *op7, const char *op8, uint32_t op8_len, zval *op9, int self_var);
void zephir_concat_vv(zval *result, zval *op1, zval *op2, int self_var);
void zephir_concat_vvs(zval *result, zval *op1, zval *op2, const char *op3, uint32_t op3_len, int self_var);
void zephir_concat_vvsv(zval *result, zval *op1, zval *op2, const char *op3, uint32_t op3_len, zval *op4, int self_var);
void zephir_concat_vvv(zval *result, zval *op1, zval *op2, zval *op3, int self_var);
void zephir_concat_vvvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, int self_var);
void zephir_concat_vvvvsvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, const char *op5, uint32_t op5_len, zval *op6, zval *op7, int self_var);
void zephir_concat_vvvvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, zval *op5, int self_var);
void zephir_concat_function(zval *result, zval *op1, zval *op2);
#endif /* ZEPHIR_KERNEL_CONCAT_H */
