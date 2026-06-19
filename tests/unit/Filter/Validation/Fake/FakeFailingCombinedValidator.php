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

namespace Phalcon\Tests\Unit\Filter\Validation\Fake;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\AbstractCombinedFieldsValidator;

/**
 * Concrete implementation of AbstractCombinedFieldsValidator whose validate()
 * always returns false, used to cover the cancelOnFail break in
 * Validation::validate()
 */
final class FakeFailingCombinedValidator extends AbstractCombinedFieldsValidator
{
    public function validate(Validation $validation, $field): bool
    {
        return false;
    }
}