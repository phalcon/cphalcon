<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Close;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Close;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class UnderscoreInvokeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testHtmlHelperCloseUnderscoreInvoke(): void
    {
        $escaper = new Escaper();
        $helper  = new Close($escaper);

        $expected = "</image>";
        $actual   = $helper("image");
        $this->assertSame($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('close');
        $expected = "</image>";
        $actual   = $locator("image");
        $this->assertSame($expected, $actual);

        $factory  = new TagFactory($escaper);
        $expected = "</image>";
        $actual   = $factory->close("image");
        $this->assertSame($expected, $actual);
    }
}
