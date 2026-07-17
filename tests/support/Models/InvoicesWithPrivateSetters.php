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
 * Model used to verify that ORM hydration writes private properties directly
 * (raw DB value, no setter) unless orm.call_setters_on_hydration is enabled.
 *
 * @see https://github.com/phalcon/cphalcon/issues/16454
 */
class InvoicesWithPrivateSetters extends Invoices
{
    public function setSecretValue($value): void
    {
        parent::setSecretValue('SETTER:' . $value);
    }
}
