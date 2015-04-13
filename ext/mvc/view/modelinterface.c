
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "mvc/view/modelinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_view_modelinterface_ce;

static const zend_function_entry phalcon_mvc_view_modelinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, setTemplate, arginfo_phalcon_mvc_view_modelinterface_settemplate)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, getTemplate, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, setVars, arginfo_phalcon_mvc_view_modelinterface_setvars)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, getVars, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, setVar, arginfo_phalcon_mvc_view_modelinterface_setvar)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, getVar, arginfo_phalcon_mvc_view_modelinterface_getvar)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, addChild, arginfo_phalcon_mvc_view_modelinterface_addchild)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, appendChild, arginfo_phalcon_mvc_view_modelinterface_appendchild)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, getChild, arginfo_phalcon_mvc_view_modelinterface_getchild)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, hasChild, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, setCaptureTo, arginfo_phalcon_mvc_view_modelinterface_setcaptureto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, getCaptureTo, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, setTerminal, arginfo_phalcon_mvc_view_modelinterface_setterminal)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, getTerminal, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, setAppend, arginfo_phalcon_mvc_view_modelinterface_setappend)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, isAppend, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, setView, arginfo_phalcon_mvc_view_modelinterface_setview)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, getView, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_ModelInterface, render, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\View\ModelInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View_ModelInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\View, ModelInterface, mvc_view_modelinterface, phalcon_mvc_view_modelinterface_method_entry);

	return SUCCESS;
}

/**
 * Set the template to be used by this model
 *
 * @param  string $template
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, setTemplate);

/**
 * Get the template to be used by this model
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, getTemplate);

/**
 * Set all the render params
 *
 * @param array $params
 * @param boolean $merge
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, setVars);

/**
 * Set a single view parameter
 *
 * @param string $key
 * @param mixed $value
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, setVar);

/**
 * Add a child model
 *
 * @param Phalcon\Mvc\View\ModelInterface $child
 * @param null|string $captureTo Optional; if specified, the "capture to" value to set on the child
 * @param null|bool $append Optional; if specified, append to child  with the same capture
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, addChild);

/**
 * Add a child model
 *
 * @param Phalcon\Mvc\View\ModelInterface $child
 * @param null|string $captureTo Optional; if specified, the "capture to" value to set on the child
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, appendChild);

/**
 * Return a child model or all child model
 *
 * @param null|string $captureTo
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, getChild);

/**
 * Does the model have any children?
 *
 * @param null|string $captureTo
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, hasChild);

/**
 * Set the name of the variable to capture this model to, if it is a child model
 *
 * @param string $capture
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, setCaptureTo);

/**
 * Get the name of the variable to which to capture this model
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, getCaptureTo);

/**
 * Set flag indicating whether or not this is considered a terminal or standalone model
 *
 * @param boolean $terminate
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, setTerminal);

/**
 * Is this considered a terminal or standalone model?
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, getTerminal);

/**
 * Set flag indicating whether or not append to child  with the same capture
 *
 * @param boolean $append
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, setAppend);

/**
 * Is this append to child  with the same capture?
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, isAppend);

/**
 * Set the view
 *
 * @param Phalcon\Mvc\ViewInterface $view
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, setAppend);

/**
 * Get the view
 *
 * @return Phalcon\Mvc\ViewInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, getView);

/**
 * Renders the view
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_ModelInterface, render);
