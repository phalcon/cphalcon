<?php
/**
 * Security.php
 * \PhalconTest\Security
 *
 * Security proxy class
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

use Phalcon\Security as PhSecurity;

class Security
{
    private $security = null;
    
    public function __construct()
    {
        $this->security = new PhSecurity();
    }

    public function __desctruct()
    {
        unset($this->security);
    }

    public function setDI($di)
	{
		$this->security->setDI($di);
	}

    public function getDI()
	{
        return $this->security->getDI();
	}

	public function setRandomBytes($randomBytes)
	{
        $this->security->setRandomBytes($randomBytes);
	}

	public function getRandomBytes()
	{
        return $this->security->getRandomBytes();
	}

	public function getSaltBytes()
	{
        return $this->security->getSaltBytes();
	}

	public function hash($password, $workFactor = 0)
	{
        return $this->security->hash($password, $workFactor);
	}

	public function checkHash($password, $passwordHash, $maxPassLength = 0)
	{
        return $this->security->checkHash($password, $passwordHash, $maxPassLength);
    }

	public function isLegacyHash($password, $passwordHash)
	{
        return $this->security->isLegacyHash($password, $passwordHash);
    }

	public function getTokenKey($numberBytes = null)
	{
        return $this->security->getTokenKey($numberBytes);
	}

	public function getToken($numberBytes = null)
	{
        return $this->security->getToken($numberBytes);
	}

	public function checkToken($tokenKey = null, $tokenValue = null)
	{
        return $this->security->checkToken($tokenKey, $tokenValue);
	}

	public function getSessionToken()
	{
        return $this->security->getSessionToken();
	}

	public function computeHmac($data, $key, $algo, $raw = false)
    {
        return $this->security->computeHmac($data, $key, $algo, $raw);
	}
}
