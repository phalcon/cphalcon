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

use Phalcon\Tag as PhTag;
//use Phalcon\Tag\Select;
//use Phalcon\Tag\Exception;
//use Phalcon\Mvc\UrlInterface;

class Tag
{
    public static function getEscaper($params)
    {
        return PhTag::getEscaper($params);
    }

    public static function renderAttributes($code, $attributes)
    {
        return PhTag::renderAttributes($code, $attributes);
    }

    public static function setDI($di)
    {
        PhTag::setDI($di);
    }

    public static function getDI()
    {
        return PhTag::getDI();
    }

    public static function getUrlService()
    {
        return PhTag::getUrlService();
    }

    public static function getEscaperService()
    {
        return PhTag::getEscaperService();
    }

    public static function setAutoescape($autoescape)
    {
        PhTag::setAutoescape($autoescape);
    }

    public static function setDefault($id, $value)
    {
        PhTag::setDefault($id, $value);
    }

    public static function setDefaults($values, $merge = false)
    {
        PhTag::setDefaults($values, $merge);
    }

    public static function displayTo($id, $value)
    {
        return PhTag::displayTo($id, $value);
    }

    public static function hasValue($name)
    {
        return PhTag::hasValue($name);
    }

    public static function getValue($name, $params = null)
    {
        return PhTag::getValue($name, $params);
    }

    public static function resetInput()
    {
        PhTag::resetInput();
    }

    public static function linkTo($parameters, $text = null, $local = true)
    {
        return PhTag::linkTo($parameters, $text, $local);
    }

    public static function colorField($parameters)
    {
        return PhTag::colorField($parameters);
    }

    public static function textField($parameters)
    {
        return PhTag::textField($parameters);
    }

    public static function numericField($parameters)
    {
        return PhTag::numericField($parameters);
    }

    public static function rangeField($parameters)
    {
        return PhTag::rangeField($parameters);
    }

    public static function emailField($parameters)
    {
        return PhTag::emailField($parameters);
    }

    public static function dateField($parameters)
    {
        return PhTag::dateField($parameters);
    }

    public static function dateTimeField($parameters)
    {
        return PhTag::dateTimeField($parameters);
    }

    public static function dateTimeLocalField($parameters)
    {
        return PhTag::dateTimeLocalField($parameters);
    }

    public static function monthField($parameters)
    {
        return PhTag::monthField($parameters);
    }

    public static function timeField($parameters)
    {
        return PhTag::timeField($parameters);
    }

    public static function weekField($parameters)
    {
        return PhTag::weekField($parameters);
    }

    public static function passwordField($parameters)
    {
        return PhTag::passwordField($parameters);
    }

    public static function hiddenField($parameters)
    {
        return PhTag::hiddenField($parameters);
    }

    public static function fileField($parameters)
    {
        return PhTag::fileField($parameters);
    }

    public static function searchField($parameters)
    {
        return PhTag::searchField($parameters);
    }

    public static function telField($parameters)
    {
        return PhTag::telField($parameters);
    }

    public static function urlField($parameters)
    {
        return PhTag::urlField($parameters);
    }

    public static function checkField($parameters)
    {
        return PhTag::checkField($parameters);
    }

    public static function radioField($parameters)
    {
        return PhTag::radioField($parameters);
    }

    public static function imageInput($parameters)
    {
        return PhTag::imageInput($parameters);
    }

    public static function submitButton($parameters)
    {
        return PhTag::submitButton($parameters);
    }

    public static function selectStatic($parameters, $data = null)
    {
        return PhTag::selectStatic($parameters, $data);
    }

    public static function select($parameters, $data = null)
    {
        return PhTag::select($parameters, $data);
    }

    public static function textArea($parameters)
    {
        return PhTag::textArea($parameters);
    }

    public static function form($parameters)
    {
        return PhTag::form($parameters);
    }

    public static function endForm()
    {
        return PhTag::endForm();
    }

    public static function setTitle($title)
    {
        return PhTag::setTitle($title);
    }

    public static function setTitleSeparator($titleSeparator)
    {
        return PhTag::setTitleSeparator($titleSeparator);
    }

    public static function appendTitle($title)
    {
        return PhTag::appendTitle($title);
    }

    public static function prependTitle($title)
    {
        return PhTag::prependTitle($title);
    }

    public static function getTitle($title)
    {
        return PhTag::getTitle($title);
    }

    public static function getTitleSeparator()
    {
        return PhTag::getTitleSeparator();
    }

    public static function stylesheetLink($parameters = null, $local = true)
    {
        return PhTag::stylesheetLink($parameters, $local);
    }

    public static function javascriptInclude($parameters = null, $local = true)
    {
        return PhTag::javascriptInclude($parameters, $local);
    }

    public static function image($parameters = null, $local = true)
    {
        return PhTag::image($parameters, $local);
    }

    public static function friendlyTitle($text, $separator = "-", $lowercase = true, $replace = null)
    {
        return PhTag::friendlyTitle($text, $separator, $lowercase, $replace);
    }

    public static function setDocType($doctype)
    {
        return PhTag::setDocType($doctype);
    }

    public static function getDocType()
    {
        return PhTag::getDocType();
    }

    public static function tagHtml($tagName, $parameters = null, $selfClose = false, $onlyStart = false, $useEol = false)
    {
        return PhTag::tagHtml($tagName, $parameters, $selfClose, $onlyStart, $useEol);
    }

    public static function tagHtmlClose($tagName, $useEol = false)
    {
        return PhTag::tagHtmlClose($tagName, $useEol);
    }
}
