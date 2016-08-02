<?php

namespace Phalcon\Test\Proxy;

use Phalcon\Escaper as PhEscaper;

/**
 * \Phalcon\Test\Proxy\Escaper
 * Escaper proxy class for \Phalcon\Escaper
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Escaper extends PhEscaper
{
    public function setEncoding($encoding)
    {
        parent::setEncoding($encoding);
    }

    public function getEncoding()
    {
        return parent::getEncoding();
    }

    public function setHtmlQuoteType($quoteType)
    {
        parent::setHtmlQuoteType($quoteType);
    }

    public function escapeHtml($text)
    {
        return parent::escapeHtml($text);
    }

    public function escapeHtmlAttr($attribute)
    {
        return parent::escapeHtmlAttr($attribute);
    }

    public function escapeCss($css)
    {
        return parent::escapeCss($css);
    }

    public function escapeJs($js)
    {
        return parent::escapeJs($js);
    }

    public function escapeUrl($url)
    {
        return parent::escapeUrl($url);
    }
}
