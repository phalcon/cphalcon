<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Models;

use Phalcon\Mvc\Model;

class InvoicesReadWrite extends Model
{
    public function initialize(): void
    {
        $this->setReadConnectionService('dbRead');
        $this->setSource('co_invoices');
        $this->setWriteConnectionService('dbWrite');
    }
}