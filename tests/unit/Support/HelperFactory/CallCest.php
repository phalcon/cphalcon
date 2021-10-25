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

namespace Phalcon\Tests\Unit\Support\HelperFactory;

use Phalcon\Support\Arr\Blacklist;
use Phalcon\Support\Arr\Chunk;
use Phalcon\Support\Arr\First;
use Phalcon\Support\Arr\FirstKey;
use Phalcon\Support\Arr\Flatten;
use Phalcon\Support\Arr\Get;
use Phalcon\Support\Arr\Group;
use Phalcon\Support\Arr\Has;
use Phalcon\Support\Arr\IsUnique;
use Phalcon\Support\Arr\Last;
use Phalcon\Support\Arr\LastKey;
use Phalcon\Support\Arr\Order;
use Phalcon\Support\Arr\Pluck;
use Phalcon\Support\Arr\Set;
use Phalcon\Support\Arr\SliceLeft;
use Phalcon\Support\Arr\SliceRight;
use Phalcon\Support\Arr\Split;
use Phalcon\Support\Arr\ToObject;
use Phalcon\Support\Arr\ValidateAll;
use Phalcon\Support\Arr\ValidateAny;
use Phalcon\Support\Arr\Whitelist;
use Phalcon\Support\File\Basename;
use Phalcon\Support\HelperFactory;
use Phalcon\Support\Json\Decode;
use Phalcon\Support\Json\Encode;
use Phalcon\Support\Number\IsBetween;
use Phalcon\Support\Str\Concat;
use Phalcon\Support\Str\CountVowels;
use Phalcon\Support\Str\Decapitalize;
use Phalcon\Support\Str\Decrement;
use Phalcon\Support\Str\DirFromFile;
use Phalcon\Support\Str\DirSeparator;
use Phalcon\Support\Str\EndsWith;
use Phalcon\Support\Str\FirstBetween;
use Phalcon\Support\Str\Friendly;
use Phalcon\Support\Str\Humanize;
use Phalcon\Support\Str\Includes;
use Phalcon\Support\Str\Increment;
use Phalcon\Support\Str\IsAnagram;
use Phalcon\Support\Str\IsLower;
use Phalcon\Support\Str\IsPalindrome;
use Phalcon\Support\Str\IsUpper;
use Phalcon\Support\Str\Len;
use Phalcon\Support\Str\Lower;
use Phalcon\Support\Str\Random;
use Phalcon\Support\Str\ReduceSlashes;
use Phalcon\Support\Str\StartsWith;
use Phalcon\Support\Str\Ucwords;
use Phalcon\Support\Str\Underscore;
use Phalcon\Support\Str\Upper;
use UnitTester;

class CallCest
{
    /**
     * Tests Phalcon\Support :: __call()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperFactoryCall(UnitTester $I)
    {
        $I->wantToTest('Support\HelperFactory - __call()');

        $factory = new HelperFactory();

        $source   = 'Phalcon';
        $expected = 7;
        $actual   = $factory->len($source);
        $I->assertEquals($expected, $actual);
    }
}
