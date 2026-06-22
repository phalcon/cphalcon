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

/**
 * Model whose setter performs an ORM query. Used to verify that setters are
 * not invoked during hydration at default settings; otherwise
 * findFirst() -> cloneResultMap() -> setInvTitle() -> findFirst() would recurse
 * infinitely.
 *
 * @see https://github.com/phalcon/cphalcon/issues/17214
 */
class InvoicesWithQuerySetter extends Invoices
{
    public function setInvTitle(?string $title): void
    {
        self::findFirst();

        $this->inv_title = 'QUERIED:' . $title;
    }
}
