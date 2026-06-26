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

namespace Phalcon\Tests\Unit\Filter\Sanitize;

use Phalcon\Filter\Sanitize\Remove;
use Phalcon\Tests\AbstractUnitTestCase;

final class RemoveTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeRemove(): void
    {
        $sanitizer = new Remove();

        $this->assertSame('Hello World', $sanitizer('Hello123 World456', ['1', '2', '3', '4', '5', '6']));
        $this->assertSame('Hello World', $sanitizer('Hello World', ''));
        $this->assertSame('Hello', $sanitizer('Hello World', ' World'));
        $this->assertSame('', $sanitizer('', 'anything'));
    }
}
