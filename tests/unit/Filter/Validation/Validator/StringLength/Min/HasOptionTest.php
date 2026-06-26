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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\StringLength\Min;

use Phalcon\Filter\Validation\Validator\StringLength\Min;
use Phalcon\Tests\AbstractUnitTestCase;

final class HasOptionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function testFilterValidationValidatorStringLengthMinHasOption(): void
    {
        $validator = new Min();

        $this->assertFalse($validator->hasOption('min'), 'Min option does not exists');

        $validator->setOption('min', 1234);
        $this->assertTrue($validator->hasOption('min'), 'Min option does exists');
    }
}
