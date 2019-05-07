
extern zend_class_entry *phalcon_html_tag_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Tag);

PHP_METHOD(Phalcon_Html_Tag, appendTitle);
PHP_METHOD(Phalcon_Html_Tag, button);
PHP_METHOD(Phalcon_Html_Tag, clear);
PHP_METHOD(Phalcon_Html_Tag, element);
PHP_METHOD(Phalcon_Html_Tag, elementClose);
PHP_METHOD(Phalcon_Html_Tag, endForm);
PHP_METHOD(Phalcon_Html_Tag, form);
PHP_METHOD(Phalcon_Html_Tag, friendlyTitle);
PHP_METHOD(Phalcon_Html_Tag, getDI);
PHP_METHOD(Phalcon_Html_Tag, getDocType);
PHP_METHOD(Phalcon_Html_Tag, getTitle);
PHP_METHOD(Phalcon_Html_Tag, getTitleSeparator);
PHP_METHOD(Phalcon_Html_Tag, getValue);
PHP_METHOD(Phalcon_Html_Tag, hasValue);
PHP_METHOD(Phalcon_Html_Tag, image);
PHP_METHOD(Phalcon_Html_Tag, inputCheckbox);
PHP_METHOD(Phalcon_Html_Tag, inputColor);
PHP_METHOD(Phalcon_Html_Tag, inputDate);
PHP_METHOD(Phalcon_Html_Tag, inputDateTime);
PHP_METHOD(Phalcon_Html_Tag, inputDateTimeLocal);
PHP_METHOD(Phalcon_Html_Tag, inputEmail);
PHP_METHOD(Phalcon_Html_Tag, inputFile);
PHP_METHOD(Phalcon_Html_Tag, inputHidden);
PHP_METHOD(Phalcon_Html_Tag, inputImage);
PHP_METHOD(Phalcon_Html_Tag, inputMonth);
PHP_METHOD(Phalcon_Html_Tag, inputNumeric);
PHP_METHOD(Phalcon_Html_Tag, inputPassword);
PHP_METHOD(Phalcon_Html_Tag, inputRadio);
PHP_METHOD(Phalcon_Html_Tag, inputRange);
PHP_METHOD(Phalcon_Html_Tag, inputSearch);
PHP_METHOD(Phalcon_Html_Tag, inputTel);
PHP_METHOD(Phalcon_Html_Tag, inputText);
PHP_METHOD(Phalcon_Html_Tag, inputTime);
PHP_METHOD(Phalcon_Html_Tag, inputUrl);
PHP_METHOD(Phalcon_Html_Tag, inputWeek);
PHP_METHOD(Phalcon_Html_Tag, javascript);
PHP_METHOD(Phalcon_Html_Tag, link);
PHP_METHOD(Phalcon_Html_Tag, prependTitle);
PHP_METHOD(Phalcon_Html_Tag, renderTitle);
PHP_METHOD(Phalcon_Html_Tag, reset);
PHP_METHOD(Phalcon_Html_Tag, select);
PHP_METHOD(Phalcon_Html_Tag, setAttribute);
PHP_METHOD(Phalcon_Html_Tag, setAttributes);
PHP_METHOD(Phalcon_Html_Tag, setDI);
PHP_METHOD(Phalcon_Html_Tag, setDocType);
PHP_METHOD(Phalcon_Html_Tag, setTitle);
PHP_METHOD(Phalcon_Html_Tag, setTitleSeparator);
PHP_METHOD(Phalcon_Html_Tag, stylesheet);
PHP_METHOD(Phalcon_Html_Tag, submit);
PHP_METHOD(Phalcon_Html_Tag, textArea);
PHP_METHOD(Phalcon_Html_Tag, getService);
PHP_METHOD(Phalcon_Html_Tag, renderAttributes);
PHP_METHOD(Phalcon_Html_Tag, renderCloseTag);
PHP_METHOD(Phalcon_Html_Tag, renderInput);
PHP_METHOD(Phalcon_Html_Tag, renderInputChecked);
PHP_METHOD(Phalcon_Html_Tag, renderSelectArray);
PHP_METHOD(Phalcon_Html_Tag, renderSelectResultset);
zend_object *zephir_init_properties_Phalcon_Html_Tag(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_tag_appendtitle, 0, 1, Phalcon\\Html\\Tag, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_appendtitle, 0, 1, IS_OBJECT, "Phalcon\\Html\\Tag", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, title, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_button, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_button, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_element, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_element, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tag)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_elementclose, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_elementclose, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tag)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_endform, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_endform, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, eol, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, eol)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_form, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_form, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, action, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, action)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_friendlytitle, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_friendlytitle, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_tag_getdi, 0, 0, Phalcon\\DiInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_getdi, 0, 0, IS_OBJECT, "Phalcon\\DiInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_getdoctype, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_getdoctype, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_gettitle, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_gettitle, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prepend, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, prepend)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, append, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, append)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_gettitleseparator, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_gettitleseparator, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_tag_getvalue, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_hasvalue, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_hasvalue, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_image, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_image, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputcheckbox, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputcheckbox, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputcolor, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputcolor, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputdate, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputdate, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputdatetime, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputdatetime, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputdatetimelocal, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputdatetimelocal, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputemail, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputemail, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputfile, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputfile, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputhidden, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputhidden, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputimage, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputimage, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputmonth, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputmonth, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputnumeric, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputnumeric, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputpassword, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputpassword, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputradio, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputradio, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputrange, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputrange, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputsearch, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputsearch, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputtel, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputtel, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputtext, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputtext, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputtime, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputtime, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputurl, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputurl, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputweek, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_inputweek, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_javascript, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_javascript, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_link, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_link, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_tag_prependtitle, 0, 1, Phalcon\\Html\\Tag, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_prependtitle, 0, 1, IS_OBJECT, "Phalcon\\Html\\Tag", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, title, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_rendertitle, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_rendertitle, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prepend, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, prepend)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, append, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, append)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_reset, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_reset, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_select, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_select, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_tag_setattribute, 0, 2, Phalcon\\Html\\Tag, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_setattribute, 0, 2, IS_OBJECT, "Phalcon\\Html\\Tag", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_tag_setattributes, 0, 1, Phalcon\\Html\\Tag, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_setattributes, 0, 1, IS_OBJECT, "Phalcon\\Html\\Tag", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, merge)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_tag_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_tag_setdoctype, 0, 1, Phalcon\\Html\\Tag, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_setdoctype, 0, 1, IS_OBJECT, "Phalcon\\Html\\Tag", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, doctype, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, doctype)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_tag_settitle, 0, 1, Phalcon\\Html\\Tag, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_settitle, 0, 1, IS_OBJECT, "Phalcon\\Html\\Tag", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, title)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_tag_settitleseparator, 0, 1, Phalcon\\Html\\Tag, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_settitleseparator, 0, 1, IS_OBJECT, "Phalcon\\Html\\Tag", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, separator, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, separator)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_stylesheet, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_stylesheet, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_submit, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_submit, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_textarea, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_textarea, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_tag_getservice, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_renderattributes, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_renderattributes, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, code, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, code)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_renderclosetag, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_renderclosetag, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, addEol, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, addEol)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_renderinput, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_renderinput, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_renderinputchecked, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_renderinputchecked, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_renderselectarray, 0, 3, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_renderselectarray, 0, 3, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, closeOption, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, closeOption)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_renderselectresultset, 0, 4, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_tag_renderselectresultset, 0, 4, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, resultset, Phalcon\\Html\\ResulsetInterface, 0)
	ZEND_ARG_INFO(0, using)
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, closeOption, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, closeOption)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_tag_method_entry) {
	PHP_ME(Phalcon_Html_Tag, appendTitle, arginfo_phalcon_html_tag_appendtitle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, button, arginfo_phalcon_html_tag_button, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, element, arginfo_phalcon_html_tag_element, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, elementClose, arginfo_phalcon_html_tag_elementclose, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, endForm, arginfo_phalcon_html_tag_endform, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, form, arginfo_phalcon_html_tag_form, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, friendlyTitle, arginfo_phalcon_html_tag_friendlytitle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, getDI, arginfo_phalcon_html_tag_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, getDocType, arginfo_phalcon_html_tag_getdoctype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, getTitle, arginfo_phalcon_html_tag_gettitle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, getTitleSeparator, arginfo_phalcon_html_tag_gettitleseparator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, getValue, arginfo_phalcon_html_tag_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, hasValue, arginfo_phalcon_html_tag_hasvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, image, arginfo_phalcon_html_tag_image, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputCheckbox, arginfo_phalcon_html_tag_inputcheckbox, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputColor, arginfo_phalcon_html_tag_inputcolor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputDate, arginfo_phalcon_html_tag_inputdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputDateTime, arginfo_phalcon_html_tag_inputdatetime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputDateTimeLocal, arginfo_phalcon_html_tag_inputdatetimelocal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputEmail, arginfo_phalcon_html_tag_inputemail, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputFile, arginfo_phalcon_html_tag_inputfile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputHidden, arginfo_phalcon_html_tag_inputhidden, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputImage, arginfo_phalcon_html_tag_inputimage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputMonth, arginfo_phalcon_html_tag_inputmonth, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputNumeric, arginfo_phalcon_html_tag_inputnumeric, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputPassword, arginfo_phalcon_html_tag_inputpassword, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputRadio, arginfo_phalcon_html_tag_inputradio, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputRange, arginfo_phalcon_html_tag_inputrange, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputSearch, arginfo_phalcon_html_tag_inputsearch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputTel, arginfo_phalcon_html_tag_inputtel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputText, arginfo_phalcon_html_tag_inputtext, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputTime, arginfo_phalcon_html_tag_inputtime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputUrl, arginfo_phalcon_html_tag_inputurl, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, inputWeek, arginfo_phalcon_html_tag_inputweek, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, javascript, arginfo_phalcon_html_tag_javascript, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, link, arginfo_phalcon_html_tag_link, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, prependTitle, arginfo_phalcon_html_tag_prependtitle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, renderTitle, arginfo_phalcon_html_tag_rendertitle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, reset, arginfo_phalcon_html_tag_reset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, select, arginfo_phalcon_html_tag_select, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, setAttribute, arginfo_phalcon_html_tag_setattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, setAttributes, arginfo_phalcon_html_tag_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, setDI, arginfo_phalcon_html_tag_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, setDocType, arginfo_phalcon_html_tag_setdoctype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, setTitle, arginfo_phalcon_html_tag_settitle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, setTitleSeparator, arginfo_phalcon_html_tag_settitleseparator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, stylesheet, arginfo_phalcon_html_tag_stylesheet, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, submit, arginfo_phalcon_html_tag_submit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, textArea, arginfo_phalcon_html_tag_textarea, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Tag, getService, arginfo_phalcon_html_tag_getservice, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Html_Tag, renderAttributes, arginfo_phalcon_html_tag_renderattributes, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Html_Tag, renderCloseTag, arginfo_phalcon_html_tag_renderclosetag, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Html_Tag, renderInput, arginfo_phalcon_html_tag_renderinput, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Html_Tag, renderInputChecked, arginfo_phalcon_html_tag_renderinputchecked, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Html_Tag, renderSelectArray, arginfo_phalcon_html_tag_renderselectarray, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Html_Tag, renderSelectResultset, arginfo_phalcon_html_tag_renderselectresultset, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
