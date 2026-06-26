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

namespace Phalcon\Tests\Unit\Html\Attributes;

use Phalcon\Html\Attributes;
use Phalcon\Tests\AbstractUnitTestCase;

final class OffsetSetTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-02
     */
    public function testHtmlAttributesOffsetSet(): void
    {
        $attributes = new Attributes();

        $attributes['class'] = 'form-control';

        $this->assertSame(
            'form-control',
            $attributes->get('class')
        );
    }
}
