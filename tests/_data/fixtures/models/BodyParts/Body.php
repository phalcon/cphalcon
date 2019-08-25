<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\BodyParts;

use Phalcon\Mvc\Model;

class Body extends Model
{
    public $id;
    public $head_1_id;
    public $head_2_id;

    public function initialize()
    {
        $this->setSource('issue12071_body');

        $this->belongsTo(
            'head_1_id',
            Head::class,
            'id',
            [
                'alias'      => 'head1',
                'foreignKey' => [
                    'allowNulls' => true,
                    'message'    => 'First head does not exists',
                ],
            ]
        );

        $this->belongsTo(
            'head_2_id',
            Head::class,
            'id',
            [
                'alias'      => 'head2',
                'foreignKey' => [
                    'allowNulls' => true,
                    'message'    => 'Second head does not exists',
                ],
            ]
        );
    }
}
