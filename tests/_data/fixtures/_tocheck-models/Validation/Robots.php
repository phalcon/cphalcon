<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Models\Validation;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\Models\RobotsParts;
use Phalcon\Validation\Validator\StringLength;

/**
 * @method static int countByType(string $type)
 * @method static Simple findByType(string $type)
 * @method static Robots findFirstById(string | int $id)
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
