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

class InvoicesOnConstruct extends Invoices
{
    public ?string $onConstructLabel = null;

    public function onConstruct(): void
    {
        $this->onConstructLabel = 'initialized';
    }
}
