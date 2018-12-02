<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Relations\Some;

use Phalcon\Mvc\Model;

class Parts extends Model
{

    public function getSource(): string
    {
        return 'parts';
    }

    public function initialize()
    {
        $this->hasMany('id', RobotsParts::class, 'parts_id', [
            'foreignKey' => [
                'message' => 'Parts cannot be deleted because is referenced by a Robot',
            ],
        ]);
    }

}
