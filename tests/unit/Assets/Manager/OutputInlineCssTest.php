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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

use const PHP_EOL;

final class OutputInlineCssTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAssetsManagerOutputInlineCss(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $css     = 'p { color: #000099 }';

        $manager->addInlineCss($css);
        $manager->useImplicitOutput(false);

        $expected = "<style type=\"text/css\">{$css}</style>" . PHP_EOL;
        $actual   = $manager->outputInlineCss();
        $this->assertSame($expected, $actual);
    }
}
