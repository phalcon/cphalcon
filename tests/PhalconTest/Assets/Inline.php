<?php
/**
 * Inline.php
 * \PhalconTest\Assets\Inline
 *
 * Inline proxy class
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

namespace PhalconTest\Assets;

use Phalcon\Assets\Inline as PhInline;

class Inline
{
    private $inln = null;

    public function __construct($type, $content, $filter = true, $attributes = null)
    {
        $this->inln = new PhInline($type, $content, $filter, $attributes);
    }

    public function __desctruct()
    {
        unset($this->inln);
    }


	public function setType($type)
	{
	    $this->inln->setType($type);
		return $this;
	}

	public function setFilter($filter)
	{
        $this->inln->setFilter($filter);
		return $this;
	}

	public function setAttributes($attributes)
	{
        $this->inln->setAttributes($attributes);
		return $this;
	}
}
