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
 * Model used to verify that ORM hydration writes protected properties
 * directly (raw DB value, no setter) at default settings.
 *
 * @see https://github.com/phalcon/cphalcon/issues/16454
 */
class InvoicesWithProtectedSetter extends Model
{
    public $inv_id;

    protected $inv_title;

    public function getInvTitle()
    {
        return $this->inv_title;
    }

    public function initialize()
    {
        $this->setSource('co_invoices');
    }

    public function setInvTitle($title): void
    {
        $this->inv_title = 'SETTER:' . $title;
    }
}
