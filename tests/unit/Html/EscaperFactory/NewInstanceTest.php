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

namespace Phalcon\Tests\Unit\Html\EscaperFactory;

use Phalcon\Html\Escaper;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\EscaperFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class NewInstanceTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testHtmlEscaperFactoryNewInstance(): void
    {
        $factory = new EscaperFactory();
        $escaper = $factory->newInstance();

        $this->assertInstanceOf(EscaperInterface::class, $escaper);
        $this->assertInstanceOf(Escaper::class, $escaper);
    }
}
