<?php
/**
 * Escaper.php
 * \PhalconTest\Escaper
 *
 * Escaper proxy class
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

use Phalcon\Escaper as PhEscaper;

class Escaper
{
    private $escaper = null;
    
    public function __construct()
    {
        $this->escaper = new PhEscaper();
    }

    public function __desctruct()
    {
        unset($this->escaper);
    }

    public function setEncoding($encoding)
	{
		$this->escaper->setEncoding($encoding);
	}

    public function getEncoding()
	{
        return $this->escaper->getEncoding();
	}

	public function setHtmlQuoteType($quoteType)
    {
        $this->escaper->setHtmlQuoteType($quoteType);
    }

	public function detectEncoding($str)
	{
        return $this->escaper->detectEncoding($str);
    }

	public function normalizeEncoding($str)
	{
        return $this->escaper->normalizeEncoding($str);
    }

	public function escapeHtml($text)
	{
        return $this->escaper->escapeHtml($text);
	}

	public function escapeHtmlAttr($attribute)
	{
        return $this->escaper->escapeHtmlAttr($attribute);
	}

	public function escapeCss($css)
	{
        return $this->escaper->escapeCss($css);
	}

	public function escapeJs($js)
	{
        return $this->escaper->escapeJs($js);
	}

	public function escapeUrl($url)
	{
        return $this->escaper->escapeUrl($url);
    }
}
