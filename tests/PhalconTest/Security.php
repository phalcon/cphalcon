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

use \Phalcon\Security as PhSecurity;
use \Phalcon\DiInterface as PhDIInterface;

class Security extends PhSecurity
{
    public function setDI(PhDIInterface $di)
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

    public function getSaltBytes()
    {
        return parent::getSaltBytes();
    }

    public function hash($password, $workFactor = 0)
    {
        return parent::hash($password, $workFactor);
    }

    public function checkHash($password, $passwordHash, $maxPassLength = 0)
    {
        return parent::checkHash($password, $passwordHash, $maxPassLength);
    }

    public function isLegacyHash($password, $passwordHash)
    {
        return parent::isLegacyHash($password, $passwordHash);
    }

    public function getTokenKey($numberBytes = null)
    {
        return parent::getTokenKey($numberBytes);
    }

    public function getToken($numberBytes = null)
    {
        return parent::getToken($numberBytes);
    }

    public function checkToken($tokenKey = null, $tokenValue = null)
    {
        return parent::checkToken($tokenKey, $tokenValue);
    }

    public function getSessionToken()
    {
        return parent::getSessionToken();
    }

    public function computeHmac($data, $key, $algo, $raw = false)
    {
        return parent::computeHmac($data, $key, $algo, $raw);
    }
}
