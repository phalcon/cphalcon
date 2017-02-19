<?php

namespace Phalcon\Test\Proxy\Security;

use Phalcon\Security\Random as PhRandom;

/**
 * \Phalcon\Test\Proxy\Security\Random
 * Random proxy class for \Phalcon\Security\Random
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Security
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Random extends PhRandom
{
    public function bytes($len = 16)
    {
        return parent::bytes($len);
    }

    public function hex($len = null)
    {
        return parent::hex($len);
    }

    public function base58($len = null)
    {
        return parent::base58($len);
    }

    public function base64($len = null)
    {
        return parent::base64($len);
    }

    public function base64Safe($len = null, $padding = false)
    {
        return parent::base64Safe($len, $padding);
    }

    public function uuid()
    {
        return parent::uuid();
    }

    public function number($len)
    {
        return parent::number($len);
    }
}
