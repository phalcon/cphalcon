<?php
/**
 * Random.php
 * \PhalconTest\Security\Random
 *
 * Random proxy class
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace PhalconTest\Security;

use \Phalcon\Security\Random as PhRandom;

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
