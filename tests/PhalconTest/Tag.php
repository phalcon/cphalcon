<?php
/**
 * Tag.php
 * \PhalconTest\Tag
 *
 * Tag proxy class
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace PhalconTest;

use \Phalcon\Tag as PhTag;
use \Phalcon\DiInterface as PhDIInterface;

class Tag extends PhTag
{
    public static function getEscaper($params)
    {
        return parent::getEscaper($params);
    }

    public static function renderAttributes($code, $attributes)
    {
        return parent::renderAttributes($code, $attributes);
    }

    public static function setDI(PhDIInterface $di)
    {
        return parent::setDI($di);
    }

    public static function getDI()
    {
        return parent::getDI();
    }

    public static function getUrlService()
    {
        return parent::getUrlService();
    }

    public static function getEscaperService()
    {
        return parent::getEscaperService();
    }

    public static function setAutoescape($autoescape)
    {
        return parent::setAutoescape($autoescape);
    }

    public static function setDefault($id, $value)
    {
        parent::setDefault($id, $value);
    }

    public static function setDefaults($values, $merge = false)
    {
        parent::setDefaults($values, $merge);
    }

    public static function displayTo($id, $value)
    {
        return parent::displayTo($id, $value);
    }

    public static function hasValue($name)
    {
        return parent::hasValue($name);
    }

    public static function getValue($name, $params = null)
    {
        return parent::getValue($name, $params);
    }

    public static function resetInput()
    {
        return parent::resetInput();
    }

    public static function linkTo($parameters, $text = null, $local = true)
    {
        return parent::linkTo($parameters, $text, $local);
    }

    public static function colorField($parameters)
    {
        return parent::colorField($parameters);
    }

    public static function textField($parameters)
    {
        return parent::textField($parameters);
    }

    public static function numericField($parameters)
    {
        return parent::numericField($parameters);
    }

    public static function rangeField($parameters)
    {
        return parent::rangeField($parameters);
    }

    public static function emailField($parameters)
    {
        return parent::emailField($parameters);
    }

    public static function dateField($parameters)
    {
        return parent::dateField($parameters);
    }

    public static function dateTimeField($parameters)
    {
        return parent::dateTimeField($parameters);
    }

    public static function dateTimeLocalField($parameters)
    {
        return parent::dateTimeLocalField($parameters);
    }

    public static function monthField($parameters)
    {
        return parent::monthField($parameters);
    }

    public static function timeField($parameters)
    {
        return parent::timeField($parameters);
    }

    public static function weekField($parameters)
    {
        return parent::weekField($parameters);
    }

    public static function passwordField($parameters)
    {
        return parent::passwordField($parameters);
    }

    public static function hiddenField($parameters)
    {
        return parent::hiddenField($parameters);
    }

    public static function fileField($parameters)
    {
        return parent::fileField($parameters);
    }

    public static function searchField($parameters)
    {
        return parent::searchField($parameters);
    }

    public static function telField($parameters)
    {
        return parent::telField($parameters);
    }

    public static function urlField($parameters)
    {
        return parent::urlField($parameters);
    }

    public static function checkField($parameters)
    {
        return parent::checkField($parameters);
    }

    public static function radioField($parameters)
    {
        return parent::radioField($parameters);
    }

    public static function imageInput($parameters)
    {
        return parent::imageInput($parameters);
    }

    public static function submitButton($parameters)
    {
        return parent::submitButton($parameters);
    }

    public static function selectStatic($parameters, $data = null)
    {
        return parent::selectStatic($parameters, $data);
    }

    public static function select($parameters, $data = null)
    {
        return parent::select($parameters, $data);
    }

    public static function textArea($parameters)
    {
        return parent::textArea($parameters);
    }

    public static function form($parameters)
    {
        return parent::form($parameters);
    }

    public static function endForm()
    {
        return parent::endForm();
    }

    public static function setTitle($title)
    {
        return parent::setTitle($title);
    }

    public static function setTitleSeparator($titleSeparator)
    {
        return parent::setTitleSeparator($titleSeparator);
    }

    public static function appendTitle($title)
    {
        return parent::appendTitle($title);
    }

    public static function prependTitle($title)
    {
        return parent::prependTitle($title);
    }

    public static function getTitle($tags = true)
    {
        return parent::getTitle($tags);
    }

    public static function getTitleSeparator()
    {
        return parent::getTitleSeparator();
    }

    public static function stylesheetLink($parameters = null, $local = true)
    {
        return parent::stylesheetLink($parameters, $local);
    }

    public static function javascriptInclude($parameters = null, $local = true)
    {
        return parent::javascriptInclude($parameters, $local);
    }

    public static function image($parameters = null, $local = true)
    {
        return parent::image($parameters, $local);
    }

    public static function friendlyTitle($text, $separator = "-", $lowercase = true, $replace = null)
    {
        return parent::friendlyTitle($text, $separator, $lowercase, $replace);
    }

    public static function setDocType($doctype)
    {
        return parent::setDocType($doctype);
    }

    public static function getDocType()
    {
        return parent::getDocType();
    }

    public static function tagHtml($tagName, $parameters = null, $selfClose = false, $onlyStart = false, $useEol = false)
    {
        return parent::tagHtml($tagName, $parameters, $selfClose, $onlyStart, $useEol);
    }

    public static function tagHtmlClose($tagName, $useEol = false)
    {
        return parent::tagHtmlClose($tagName, $useEol);
    }
}
