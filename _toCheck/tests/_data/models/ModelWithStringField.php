<?php

namespace Phalcon\Test\Models;


use Phalcon\Mvc\Model;

/**
 * \Phalcon\Test\Models\ModelWithStringField
 *
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Nikolay Sumrak <nikolassumrak@gmail.com>
 * @package   Phalcon\Test\Models
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ModelWithStringField extends Model
{
    /**
     * @var int
     */
    public $id;
    /**
     * @var string
     */
    public $field;

    /**
     * @return string
     */
    public function getSource()
    {
        return 'table_with_string_field';
    }

    public function allowEmptyStringValue()
    {
        $this->allowEmptyStringValues([
            'field'
        ]);
    }

    public function disallowEmptyStringValue()
    {
        $this->allowEmptyStringValues([]);
    }
}