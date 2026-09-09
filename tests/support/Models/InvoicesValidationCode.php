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

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\PresenceOf;

/**
 * Class InvoicesValidationCode
 *
 * Runs a validator that carries a `code` option. The code must reach the
 * message that getMessages() returns.
 */
class InvoicesValidationCode extends Invoices
{
    /**
     * @return bool
     */
    protected function validation(): bool
    {
        $validator = new Validation();
        $validator->add(
            'inv_title',
            new PresenceOf(
                [
                    'code'    => 20,
                    'message' => 'The title is required',
                ]
            )
        );

        return $this->validate($validator);
    }
}
