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

namespace Phalcon\Tests\Unit\Forms\Fake;

use Phalcon\Forms\Element\Check;
use Phalcon\Forms\Element\Date;
use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\File;
use Phalcon\Forms\Element\Hidden;
use Phalcon\Forms\Element\Numeric;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Submit;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Element\TextArea;

/**
 * Trait GdTrait
 */
trait FormsTrait
{
    /**
     * @return string[][]
     */
    public static function getExamples(): array
    {
        return [
            [Check::class],
            [Date::class],
            [Email::class],
            [File::class],
            [Hidden::class],
            [Numeric::class],
            [Password::class],
            [Radio::class],
            [Select::class],
            [Submit::class],
            [Text::class],
            [TextArea::class],
        ];
    }

    /**
     * @return string[][]
     */
    public static function getExamplesWithoutSelect(): array
    {
        return [
            [Check::class],
            [Date::class],
            [Email::class],
            [File::class],
            [Hidden::class],
            [Numeric::class],
            [Password::class],
            [Radio::class],
            [Submit::class],
            [Text::class],
            [TextArea::class],
        ];
    }
}
