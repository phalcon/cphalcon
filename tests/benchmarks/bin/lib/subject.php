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

namespace Phalcon\Tests\Benchmarks\Bin;

use PhpBench\Attributes\BeforeMethods;
use ReflectionMethod;

/**
 * Creates the benchmark class of a subject and calls its #[BeforeMethods] methods (of the class and of the
 * subject). Returns the object. The subject method is not called.
 */
function prepareSubject(string $class, string $method): object
{
    $subjectMethod = new ReflectionMethod($class, $method);
    $setUpMethods  = [];
    foreach ([$subjectMethod->getDeclaringClass(), $subjectMethod] as $source) {
        foreach ($source->getAttributes(BeforeMethods::class) as $attribute) {
            array_push($setUpMethods, ...$attribute->newInstance()->methods);
        }
    }

    $subject = new $class();
    foreach ($setUpMethods as $setUpMethod) {
        $subject->$setUpMethod();
    }

    return $subject;
}
