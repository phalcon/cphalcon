<?php

namespace Phalcon\Test\Models\BodyParts;

use Phalcon\Mvc\Model;
use Phalcon\Test\Models\BodyParts\Head;
use Phalcon\Test\ModelRepositories\BodyParts\BodyRepository;

/**
 * \Phalcon\Test\Models\Body
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Radek Crlík <radekcrlik@gmail.com>
 * @package   Phalcon\Test\Models\BodyParts
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Body extends Model
{
    public $id;
    public $head_1_id;
    public $head_2_id;

    public static function getRepositoryClass()
    {
        return BodyRepository::class;
    }
}
