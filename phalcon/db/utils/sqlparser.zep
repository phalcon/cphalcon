/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Doctrine DBAL Team                                            |
 |          Vladimir Khramov <quant13@gmail.com>                          |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Db\Utils;

use Phalcon\Db\Exception;
use Phalcon\Db\Column;

/**
 * Phalcon\Db\Utils\SQLParser
 *
 * Utility class that parses sql statements with regard to types and parameters.
 * Port of class SQLParserUtils of Doctrine DBAL.
 */
class SQLParser
{
	const POSITIONAL_TOKEN = "\\?";
	const NAMED_TOKEN = "(?<!:):[a-zA-Z0-9_]+";

	// Quote characters within string literals can be preceded by a backslash.
	const ESCAPED_SINGLE_QUOTED_TEXT   = "'(?:[^'\\\\]|\\\\'?)*'";
	const ESCAPED_DOUBLE_QUOTED_TEXT   = "\"(?:[^\"\\\\]|\\\\\"?)*\"";
	const ESCAPED_BACKTICK_QUOTED_TEXT = "`(?:[^`\\\\]|\\\\`?)*`";
	const ESCAPED_BRACKET_QUOTED_TEXT  = "\\[(?:[^\\]])*\\]"; //"

	/**
	 * Gets an array of the placeholders in an sql statements as keys and their positions in the query string.
	 *
	 * Returns an integer => integer pair (indexed from zero) for a positional statement
	 * and a string => int[] pair for a named statement.
	 *
	 * @param string  statement
	 * @param boolean isPositional
	 *
	 * @return array
	 */
	static public function getPlaceholderPositions(string statement, boolean isPositional = true)
	{
		var matches = null, fragment, placeholder, paramMap = [];
		string match, token;
		int pos;

		let match = isPositional ? "?" : ":";
		if (strpos(statement, match) === false) {
			return [];
		}
		let token = isPositional ? self::POSITIONAL_TOKEN : self::NAMED_TOKEN;
		for fragment in self::getUnquotedStatementFragments(statement) {
			preg_match_all("/" . token . "/", fragment[0], matches, PREG_OFFSET_CAPTURE);
			for placeholder in matches[0] {
				if isPositional {
					let paramMap[] = placeholder[1] + fragment[1];
				} else {
					let pos = placeholder[1] + fragment[1];
					let paramMap[pos] = substr(placeholder[0], 1, strlen(placeholder[0]));
				}
			}
		}
		return paramMap;
	}

	/**
	 * For a positional query this method can rewrite the sql statement with regard to array parameters.
	 *
	 * @param string query  The SQL query to execute.
	 * @param array  params The parameters to bind to the query.
	 * @param array  types  The types the previous parameters are in.
	 *
	 * @return array
	 *
	 * @throws Exception
	 */
	static public function expandListParameters(string query, var params, var types)
	{
		var arrayPositions = [], isPositional, bindIndex = -1, name, paramOffset,
			queryOffset, needle, needlePos, typesOrd, paramsOrd, paramPos, count,
			paramsExpanded, typesExpanded, typesForExpand, expandStr,
			pos, paramName, paramLen, value, val, param, processTypes;

		let processTypes = typeof types == "array" && count(types);
		let isPositional = is_int(key(params));

		if (isPositional) {
			ksort(params);
			if processTypes {
				ksort(types);
			}
		}

		for name, param in params {
			let bindIndex = bindIndex+1;

			if typeof param != "array" {
				continue;
			}

			if (isPositional) {
				let name = bindIndex;
			}

			let arrayPositions[name] = false;
		}

		if empty arrayPositions {
			return [query, params, types];
		}

		let paramPos = self::getPlaceholderPositions(query, isPositional);

		if (isPositional) {
			let paramOffset = 0;
			let queryOffset = 0;
			let paramsExpanded = array_values(params);
			if processTypes {
				let typesExpanded = array_values(types);
			}

			for needle, needlePos in paramPos {
				if !isset arrayPositions[needle] {
					continue;
				}

				let needle = needle + paramOffset;
				let needlePos = needlePos + queryOffset;
				let count = count(paramsExpanded[needle]);

				let paramsExpanded = array_merge(
					array_slice(paramsExpanded, 0, needle),
					paramsExpanded[needle],
					array_slice(paramsExpanded, needle + 1)
				);

				if processTypes {
					let typesForExpand = count ? array_fill(0, count, typesExpanded[needle] - Column::BIND_ARRAY_PARAM_OFFSET) : [];
					let typesExpanded = array_merge(
						array_slice(typesExpanded, 0, needle),
						typesForExpand,
						array_slice(typesExpanded, needle + 1)
					);
				}

				let expandStr = count ? implode(", ", array_fill(0, count, "?")) : "NULL";
				let query = substr(query, 0, needlePos) . expandStr . substr(query, needlePos + 1);

				let paramOffset = paramOffset + (count - 1); // Grows larger by number of parameters minus the replaced needle.
				let queryOffset = queryOffset + (strlen(expandStr) - 1);
			}

			return [query, paramsExpanded, processTypes ? typesExpanded : types];
		}

		let queryOffset = 0;
		let typesOrd = [];
		let paramsOrd = [];

		for pos, paramName in paramPos {
			let paramLen = strlen(paramName) + 1;
			let value = static::extractParam(paramName, params, true);

			if !isset arrayPositions[paramName] && !isset arrayPositions[":" . paramName] {
				let pos = pos + queryOffset;
				let queryOffset = queryOffset - (paramLen - 1);
				let paramsOrd[] = value;
				if processTypes {
					let typesOrd[] = static::extractParam(paramName, types, false, Column::BIND_PARAM_STR);
				}
				let query = substr(query, 0, pos) . "?" . substr(query, (pos + paramLen));

				continue;
			}

			let count = count(value);
			let expandStr = count > 0 ? implode(", ", array_fill(0, count, "?")) : "NULL";

			for val in value {
				let paramsOrd[] = val;
				if processTypes {
					let typesOrd[]  = static::extractParam(paramName, types, false) - Column::BIND_ARRAY_PARAM_OFFSET;
				}
			}

			let pos = pos + queryOffset;
			let queryOffset = queryOffset + (strlen(expandStr) - paramLen);
			let query = substr(query, 0, pos) . expandStr . substr(query, (pos + paramLen));
		}

		return [query, paramsOrd, processTypes ? typesOrd : types];
	}

	/**
	 * Slice the SQL statement around pairs of quotes and
	 * return string fragments of SQL outside of quoted literals.
	 * Each fragment is captured as a 2-element array:
	 *
	 * 0 => matched fragment string,
	 * 1 => offset of fragment in $statement
	 *
	 * @param string statement
	 * @return array
	 */
	static private function getUnquotedStatementFragments(string statement)
	{
		var fragments = null;
		string literal;

		let literal = self::ESCAPED_SINGLE_QUOTED_TEXT . "|" .
					  self::ESCAPED_DOUBLE_QUOTED_TEXT . "|" .
					  self::ESCAPED_BACKTICK_QUOTED_TEXT . "|" .
					  self::ESCAPED_BRACKET_QUOTED_TEXT;
		preg_match_all("/([^'\"`\[]+)(?:" . literal . ")?/s", statement, fragments, PREG_OFFSET_CAPTURE);//"

		return fragments[1];
	}

	/**
	 * @param string paramName      The name of the parameter (without a colon in front)
	 * @param array  paramsOrTypes  A hash of parameters or types
	 * @param bool   isParam
	 * @param mixed  defaultValue   An optional default value. If omitted, an exception is thrown
	 *
	 * @throws Exception
	 * @return mixed
	 */
	static private function extractParam(string paramName, array paramsOrTypes, bool isParam, var defaultValue = null)
	{
		if (array_key_exists(paramName, paramsOrTypes)) {
			return paramsOrTypes[paramName];
		}

		// Hash keys can be prefixed with a colon for compatibility
		if (array_key_exists(":" . paramName, paramsOrTypes)) {
			return paramsOrTypes[":" . paramName];
		}

		if (null !== defaultValue) {
			return defaultValue;
		}

		if (isParam) {
			throw new Exception("Missing param '" . paramName . "'");
		}

		throw new Exception("Missing type '" . paramName . "'");
	}
}
