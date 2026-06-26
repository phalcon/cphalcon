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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\StringLength\Max;

use Phalcon\Filter\Validation\Validator\StringLength\Max;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetOptionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function testFilterValidationValidatorStringLengthMaxGetOption(): void
    {
        $validator = new Max();

        $this->assertSame(null, $validator->getOption('max'), 'Max option is null by default');

        $expected = 1234;
        $validator->setOption('max', $expected);
        $this->assertSame($expected, $validator->getOption('max'), 'Max option is 1234');

        $expected = '1234';
        $validator->setOption('max', $expected);
        $this->assertSame($expected, $validator->getOption('max'), 'Max option is "1234"');
    }
}
