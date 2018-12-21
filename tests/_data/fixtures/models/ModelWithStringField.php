<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

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
    public function getSource(): string
    {
        return 'table_with_string_field';
    }

    public function allowEmptyStringValue()
    {
        $this->allowEmptyStringValues([
            'field',
        ]);
    }

    public function disallowEmptyStringValue()
    {
        $this->allowEmptyStringValues([]);
    }
}
