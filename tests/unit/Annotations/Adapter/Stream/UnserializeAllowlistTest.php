<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Annotations\Adapter\Stream;

use Phalcon\Annotations\Adapter\Stream;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Annotations\Fake\AnnotationInjectionProbe;

final class UnserializeAllowlistTest extends AbstractUnitTestCase
{
    /**
     * A planted cache file must not instantiate an arbitrary class: the read
     * restricts unserialize to the annotation classes, so an injected object's
     * __wakeup() never runs (CWE-502). The read is a miss.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17773
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testAnnotationsAdapterStreamReadBlocksObjectInjection(): void
    {
        $dir = Talon::settings()->outputPath('tests/annotations-d7/');
        if (!is_dir($dir)) {
            mkdir($dir, 0777, true);
        }

        AnnotationInjectionProbe::$woken = false;

        $payload = serialize(new AnnotationInjectionProbe());
        $path    = $dir . 'probe.php';
        file_put_contents($path, $payload);

        $adapter = new Stream(['annotationsDir' => $dir]);

        $this->assertFalse($adapter->read('probe'));
        $this->assertFalse(AnnotationInjectionProbe::$woken);

        @unlink($path);
    }
}
