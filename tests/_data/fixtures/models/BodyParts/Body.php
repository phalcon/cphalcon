<?php

namespace Phalcon\Test\Models\BodyParts;

use Phalcon\Mvc\Model;
use Phalcon\Test\Models\BodyParts\Head;

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

    public function initialize()
    {
        $this->setSource('issue12071_body');

        $this->belongsTo(
            'head_1_id',
            Head::class,
            'id',
            [
                'alias' => 'head1',
                "foreignKey" => [
                    "allowNulls" => true,
                    "message" => "First head does not exists"
                ]
            ]
        );

        $this->belongsTo(
            'head_2_id',
            Head::class,
            'id',
            [
                'alias' => 'head2',
                "foreignKey" => [
                    "allowNulls" => true,
                    "message" => "Second head does not exists"
                ]
            ]
        );
    }
}
