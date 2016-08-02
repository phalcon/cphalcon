<?php

namespace Phalcon\Test\Proxy;

use Phalcon\Crypt as PhCrypt;

/**
 * \Phalcon\Test\Proxy\Crypt
 * Escaper proxy class for \Phalcon\Crypt
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
class Crypt extends PhCrypt
{
    public function setPadding($scheme)
    {
        return parent::setPadding($scheme);
    }

    public function setCipher($cipher)
    {
        return parent::setCipher($cipher);
    }

    public function getCipher()
    {
        return parent::getCipher();
    }

    public function setMode($mode)
    {
        return parent::setMode($mode);
    }

    public function getMode()
    {
        return parent::getMode();
    }

    public function setKey($key)
    {
        return parent::setKey($key);
    }

    public function getKey()
    {
        return parent::getKey();
    }

    public function encrypt($text, $key = null)
    {
        return parent::encrypt($text, $key);
    }

    public function decrypt($text, $key = null)
    {
        return parent::decrypt($text, $key);
    }

    public function encryptBase64($text, $key = null, $safe = false)
    {
        return parent::encryptBase64($text, $key, $safe);
    }

    public function decryptBase64($text, $key = null, $safe = false)
    {
        return parent::decryptBase64($text, $key, $safe);
    }

    public function getAvailableCiphers()
    {
        return parent::getAvailableCiphers();
    }

    public function getAvailableModes()
    {
        return parent::getAvailableModes();
    }

}
