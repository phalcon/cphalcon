<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Models;

use Phalcon\Mvc\Model;

/**
 * Model used to verify that ORM hydration of an undeclared property keeps
 * routing through __set()/possibleSetter() (legacy behavior, unchanged by
 * the #16454 fix for private properties).
 *
 * @see https://github.com/phalcon/cphalcon/issues/16454
 */
class InvoicesWithUndeclaredSetter extends Model
{
    public $inv_id;

    public function initialize()
    {
        $this->setSource('co_invoices');
    }

    public function setInvTitle($title): void
    {
        $this->inv_title = 'SETTER:' . $title;
    }
}
