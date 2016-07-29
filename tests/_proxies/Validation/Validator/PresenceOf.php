<?php

namespace Phalcon\Test\Proxy\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\Validator\PresenceOf as PhPresenceOf;

/**
 * \Phalcon\Test\Proxy\Validation\Validator\PresenceOf
 * A proxy class for \Phalcon\Validation\Validator\PresenceOf
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Validation\Validator
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class PresenceOf extends PhPresenceOf
{
    public function validate(Validation $validation, $field)
    {
        return parent::validate($validation, $field);
    }
}
