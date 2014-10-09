<?php
/**
 * Headers.php
 * \PhalconTest\Http\Response\Headers
 *
 * Http Response Headers proxy class
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

namespace PhalconTest\Http\Response;

use Phalcon\Http\Response\Headers as PhHeaders;

class Headers
{
    private $headers = null;
    
    public function __construct($content = null, $code = null, $status = null)
    {
        $this->headers = new PhHeaders($content, $code, $status);
    }

    public function __desctruct()
    {
        unset($this->headers);
    }

    public function set($name, $value)
	{
        $this->headers->set($name, $value);
	}

    public function get($name)
	{
        $this->headers->get($name);
	}

    public function setRaw($header)
	{
        $this->headers->setRaw($header);
	}

    public function remove($header)
	{
        $this->headers->remove($header);
	}

	public function send()
    {
        $this->headers->send();
	}

	public function reset()
    {
        $this->headers->reset();
	}

	public function toArray()
    {
        return $this->headers->toArray();
	}

	public static function __set_state($data)
	{
        return PhHeaders::__set_state($data);
	}
}
