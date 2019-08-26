<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
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

    public function initialize()
    {
        $this->setSource('table_with_string_field');
    }

    public function allowEmptyStringValue()
    {
        $this->allowEmptyStringValues(
            [
                'field',
            ]
        );
    }

    public function disallowEmptyStringValue()
    {
        $this->allowEmptyStringValues(
            []
        );
    }
}
