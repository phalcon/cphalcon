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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\Uniqueness;

use Phalcon\Filter\Validation\Validator\Uniqueness;
use Phalcon\Tests\AbstractUnitTestCase;

final class HasOptionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFilterValidationValidatorUniquenessHasOption(): void
    {
        $validator = new Uniqueness(
            [
                'message' => 'This is a message',
            ]
        );

        $this->assertFalse($validator->hasOption('option'));
    }
}
