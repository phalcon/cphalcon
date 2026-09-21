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

namespace Phalcon\Tests\Unit\Annotations\AttributesReader;

use Phalcon\Annotations\AttributesReader;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

final class ParseNamesTest extends AbstractUnitTestCase
{
    public function setUp(): void
    {
        $includeFile = Talon::settings()
                            ->supportPath('assets/Annotations/TestClassAttributes.php')
        ;

        require_once $includeFile;
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-20
     */
    public function testAnotherLibraryAttributeKeepsTheFullName(): void
    {
        $reader  = new AttributesReader();
        $parsing = $reader->parse('TestClassAttributes');

        $this->assertSame('Sample\Other\Marker', $parsing['class'][1]['name']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-20
     */
    public function testAPhalconAttributeGetsTheShortName(): void
    {
        $reader  = new AttributesReader();
        $parsing = $reader->parse('TestClassAttributes');

        $this->assertSame('RoutePrefix', $parsing['class'][0]['name']);
    }
}
