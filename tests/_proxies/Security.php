<?php

namespace Phalcon\Test\Proxy;

use Phalcon\Security as PhSecurity;
use Phalcon\DiInterface;

/**
 * \Phalcon\Test\Proxy\Security
 * Security proxy class for \Phalcon\Security
 *
 * @copyright (c) 2011-2017 Phalcon Team
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
class Security extends PhSecurity
{
    public function setDI(DiInterface $di)
    {
        parent::setDI($di);
    }

    public function getDI()
    {
        return parent::getDI();
    }

    public function setRandomBytes($randomBytes)
    {
        parent::setRandomBytes($randomBytes);
    }

    public function getRandomBytes()
    {
        return parent::getRandomBytes();
    }

    public function getSaltBytes($numberBytes = 0)
    {
        return parent::getSaltBytes($numberBytes);
    }

    public function hash($password, $workFactor = 0)
    {
        return parent::hash($password, $workFactor);
    }

    public function checkHash($password, $passwordHash, $maxPassLength = 0)
    {
        return parent::checkHash($password, $passwordHash, $maxPassLength);
    }

    public function isLegacyHash($passwordHash)
    {
        return parent::isLegacyHash($passwordHash);
    }

    public function getTokenKey()
    {
        return parent::getTokenKey();
    }

    public function getToken()
    {
        return parent::getToken();
    }

    public function checkToken($tokenKey = null, $tokenValue = null, $destroyIfValid = true)
    {
        return parent::checkToken($tokenKey, $tokenValue, $destroyIfValid);
    }

    public function getSessionToken()
    {
        return parent::getSessionToken();
    }

    /**
     * @param string $data
     * @param string $key
     * @param string $algo
     * @param bool $raw
     * @return string
     */
    public function computeHmac($data, $key, $algo, $raw = false)
    {
        return parent::computeHmac($data, $key, $algo, $raw);
    }
}
