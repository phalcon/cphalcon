<?php

namespace Phalcon\Test\Models\Validation;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Validation;
use Phalcon\Validation\Validator\StringLength;

/**
 * \Phalcon\Test\Models\Validation\Robots
 *
 * @method static int countByType(string $type)
 * @method static Simple findByType(string $type)
 * @method static Robots findFirstById(string | int $id)
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Models\Validation
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Robots extends Model
{
    public function initialize()
    {
        $this->hasMany(
            'id',
            RobotsParts::class,
            'robots_id',
            [
                'foreignKey' => true,
                'reusable'   => false,
                'alias'      => 'parts',
            ]
        );
    }

    public function validation()
    {
        $validation = new Validation();
        $validation->add(
            'name',
            new StringLength(
                [
                    'min'  => '7',
                    'max'  => '50',
                    'code' => 20,
                ]
            )
        );

        return $this->validate($validation);
    }
}
