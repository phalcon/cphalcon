
extern zend_class_entry *phalcon_tag_ce;

ZEPHIR_INIT_CLASS(Phalcon_Tag);

PHP_METHOD(Phalcon_Tag, getEscaper);
PHP_METHOD(Phalcon_Tag, renderAttributes);
PHP_METHOD(Phalcon_Tag, setDI);
PHP_METHOD(Phalcon_Tag, getDI);
PHP_METHOD(Phalcon_Tag, getUrlService);
PHP_METHOD(Phalcon_Tag, getEscaperService);
PHP_METHOD(Phalcon_Tag, setAutoescape);
PHP_METHOD(Phalcon_Tag, setDefault);
PHP_METHOD(Phalcon_Tag, setDefaults);
PHP_METHOD(Phalcon_Tag, displayTo);
PHP_METHOD(Phalcon_Tag, hasValue);
PHP_METHOD(Phalcon_Tag, getValue);
PHP_METHOD(Phalcon_Tag, resetInput);
PHP_METHOD(Phalcon_Tag, linkTo);
PHP_METHOD(Phalcon_Tag, _inputField);
PHP_METHOD(Phalcon_Tag, _inputFieldChecked);
PHP_METHOD(Phalcon_Tag, colorField);
PHP_METHOD(Phalcon_Tag, textField);
PHP_METHOD(Phalcon_Tag, numericField);
PHP_METHOD(Phalcon_Tag, rangeField);
PHP_METHOD(Phalcon_Tag, emailField);
PHP_METHOD(Phalcon_Tag, dateField);
PHP_METHOD(Phalcon_Tag, dateTimeField);
PHP_METHOD(Phalcon_Tag, dateTimeLocalField);
PHP_METHOD(Phalcon_Tag, monthField);
PHP_METHOD(Phalcon_Tag, timeField);
PHP_METHOD(Phalcon_Tag, weekField);
PHP_METHOD(Phalcon_Tag, passwordField);
PHP_METHOD(Phalcon_Tag, hiddenField);
PHP_METHOD(Phalcon_Tag, fileField);
PHP_METHOD(Phalcon_Tag, searchField);
PHP_METHOD(Phalcon_Tag, telField);
PHP_METHOD(Phalcon_Tag, urlField);
PHP_METHOD(Phalcon_Tag, checkField);
PHP_METHOD(Phalcon_Tag, radioField);
PHP_METHOD(Phalcon_Tag, imageInput);
PHP_METHOD(Phalcon_Tag, submitButton);
PHP_METHOD(Phalcon_Tag, selectStatic);
PHP_METHOD(Phalcon_Tag, select);
PHP_METHOD(Phalcon_Tag, textArea);
PHP_METHOD(Phalcon_Tag, form);
PHP_METHOD(Phalcon_Tag, endForm);
PHP_METHOD(Phalcon_Tag, setTitle);
PHP_METHOD(Phalcon_Tag, setTitleSeparator);
PHP_METHOD(Phalcon_Tag, appendTitle);
PHP_METHOD(Phalcon_Tag, prependTitle);
PHP_METHOD(Phalcon_Tag, getTitle);
PHP_METHOD(Phalcon_Tag, getTitleSeparator);
PHP_METHOD(Phalcon_Tag, stylesheetLink);
PHP_METHOD(Phalcon_Tag, javascriptInclude);
PHP_METHOD(Phalcon_Tag, image);
PHP_METHOD(Phalcon_Tag, friendlyTitle);
PHP_METHOD(Phalcon_Tag, setDocType);
PHP_METHOD(Phalcon_Tag, getDocType);
PHP_METHOD(Phalcon_Tag, tagHtml);
PHP_METHOD(Phalcon_Tag, tagHtmlClose);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_getescaper, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_renderattributes, 0, 0, 2)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setautoescape, 0, 0, 1)
	ZEND_ARG_INFO(0, autoescape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdefault, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_displayto, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_hasvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_getvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_linkto, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag__inputfield, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, asValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag__inputfieldchecked, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_colorfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_textfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_numericfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_rangefield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_emailfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_datefield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_datetimefield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_datetimelocalfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_monthfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_timefield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_weekfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_passwordfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_hiddenfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_filefield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_searchfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_telfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_urlfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_checkfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_radiofield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_imageinput, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_submitbutton, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_selectstatic, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_select, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_textarea, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_form, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_settitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_settitleseparator, 0, 0, 1)
	ZEND_ARG_INFO(0, titleSeparator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_appendtitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_prependtitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_gettitle, 0, 0, 0)
	ZEND_ARG_INFO(0, tags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_stylesheetlink, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_javascriptinclude, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_image, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_friendlytitle, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, separator)
	ZEND_ARG_INFO(0, lowercase)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdoctype, 0, 0, 1)
	ZEND_ARG_INFO(0, doctype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_taghtml, 0, 0, 1)
	ZEND_ARG_INFO(0, tagName)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, selfClose)
	ZEND_ARG_INFO(0, onlyStart)
	ZEND_ARG_INFO(0, useEol)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_taghtmlclose, 0, 0, 1)
	ZEND_ARG_INFO(0, tagName)
	ZEND_ARG_INFO(0, useEol)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_tag_method_entry) {
	PHP_ME(Phalcon_Tag, getEscaper, arginfo_phalcon_tag_getescaper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, renderAttributes, arginfo_phalcon_tag_renderattributes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setDI, arginfo_phalcon_tag_setdi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getDI, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getUrlService, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getEscaperService, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setAutoescape, arginfo_phalcon_tag_setautoescape, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setDefault, arginfo_phalcon_tag_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setDefaults, arginfo_phalcon_tag_setdefaults, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, displayTo, arginfo_phalcon_tag_displayto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, hasValue, arginfo_phalcon_tag_hasvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getValue, arginfo_phalcon_tag_getvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, resetInput, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, linkTo, arginfo_phalcon_tag_linkto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, _inputField, arginfo_phalcon_tag__inputfield, ZEND_ACC_STATIC|ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Tag, _inputFieldChecked, arginfo_phalcon_tag__inputfieldchecked, ZEND_ACC_STATIC|ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Tag, colorField, arginfo_phalcon_tag_colorfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, textField, arginfo_phalcon_tag_textfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, numericField, arginfo_phalcon_tag_numericfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, rangeField, arginfo_phalcon_tag_rangefield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, emailField, arginfo_phalcon_tag_emailfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, dateField, arginfo_phalcon_tag_datefield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, dateTimeField, arginfo_phalcon_tag_datetimefield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, dateTimeLocalField, arginfo_phalcon_tag_datetimelocalfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, monthField, arginfo_phalcon_tag_monthfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, timeField, arginfo_phalcon_tag_timefield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, weekField, arginfo_phalcon_tag_weekfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, passwordField, arginfo_phalcon_tag_passwordfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, hiddenField, arginfo_phalcon_tag_hiddenfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, fileField, arginfo_phalcon_tag_filefield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, searchField, arginfo_phalcon_tag_searchfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, telField, arginfo_phalcon_tag_telfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, urlField, arginfo_phalcon_tag_urlfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, checkField, arginfo_phalcon_tag_checkfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, radioField, arginfo_phalcon_tag_radiofield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, imageInput, arginfo_phalcon_tag_imageinput, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, submitButton, arginfo_phalcon_tag_submitbutton, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, selectStatic, arginfo_phalcon_tag_selectstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, select, arginfo_phalcon_tag_select, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, textArea, arginfo_phalcon_tag_textarea, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, form, arginfo_phalcon_tag_form, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, endForm, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setTitle, arginfo_phalcon_tag_settitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setTitleSeparator, arginfo_phalcon_tag_settitleseparator, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, appendTitle, arginfo_phalcon_tag_appendtitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, prependTitle, arginfo_phalcon_tag_prependtitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getTitle, arginfo_phalcon_tag_gettitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getTitleSeparator, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, stylesheetLink, arginfo_phalcon_tag_stylesheetlink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, javascriptInclude, arginfo_phalcon_tag_javascriptinclude, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, image, arginfo_phalcon_tag_image, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, friendlyTitle, arginfo_phalcon_tag_friendlytitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setDocType, arginfo_phalcon_tag_setdoctype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getDocType, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, tagHtml, arginfo_phalcon_tag_taghtml, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, tagHtmlClose, arginfo_phalcon_tag_taghtmlclose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
