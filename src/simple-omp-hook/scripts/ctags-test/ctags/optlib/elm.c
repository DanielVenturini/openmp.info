/*
 * Generated by ./misc/optlib2c from optlib/elm.ctags, Don't edit this manually.
 */
#include "general.h"
#include "parse.h"
#include "routines.h"


static void initializeElmParser (const langType language CTAGS_ATTR_UNUSED)
{
}

extern parserDefinition* ElmParser (void)
{
	static const char *const extensions [] = {
		"elm",
		NULL
	};

	static const char *const aliases [] = {
		NULL
	};

	static const char *const patterns [] = {
		NULL
	};

	static roleDefinition ElmModuleRoleTable [] = {
		{ true, "imported", "imported module" },
	};
	static kindDefinition ElmKindTable [] = {
		{
		  true, 'm', "module", "Module",
		  ATTACH_ROLES(ElmModuleRoleTable),
		},
		{
		  true, 'n', "namespace", "Renamed Imported Module",
		},
		{
		  true, 'p', "port", "Port",
		},
		{
		  true, 't', "type", "Type Definition",
		},
		{
		  true, 'c', "constructor", "Type Constructor",
		},
		{
		  true, 'a', "alias", "Type Alias",
		},
		{
		  true, 'f', "function", "Functions",
		},
	};
	static tagRegexTable ElmTagRegexTable [] = {
		{"^(port[[:blank:]]+)?module[[:blank:]]+([[:upper:]][[:alnum:]_.]*)", "\\2",
		"m", "{scope=push}{exclusive}", NULL, false},
		{"^import[[:blank:]]+[[:alnum:]_.]+[[:blank:]]+as[[:blank:]]+([[:alnum:]]+)", "\\1",
		"n", "{scope=clear}{exclusive}", NULL, false},
		{"^import[[:blank:]]+([[:alnum:]_.]+)[[:blank:]]exposing", "\\1",
		"m", "{scope=clear}{exclusive}{_role=imported}", NULL, false},
		{"^import[[:blank:]]+([[:alnum:]_.]+)", "\\1",
		"m", "{scope=clear}{exclusive}{_role=imported}", NULL, false},
		{"^port[[:blank:]]+([[:lower:]][[:alnum:]_]*).*", "\\1",
		"p", "{scope=clear}{exclusive}", NULL, false},
		{"^type +([[:upper:]][[:alnum:]_]*.*)", "\\1",
		"t", "{scope=set}{exclusive}", NULL, false},
		{"^[[:blank:]]+[|=][[:blank:]]+([[:upper:]][[:alnum:]_]*.*)$", "\\1",
		"c", "{scope=ref}{exclusive}", NULL, false},
		{"^type[[:blank:]]+alias[[:blank:]]+([[:upper:]][[:alnum:]_]*[[:blank:][:alnum:]_]*)", "\\1",
		"a", "{scope=set}{exclusive}", NULL, false},
		{"^([[:lower:]_][[:alnum:]_]*)[^=]*=$", "\\1",
		"f", "{scope=set}", NULL, false},
		{"^[[:blank:]]+([[:lower:]_][[:alnum:]_]*)[^=]*=$", "\\1",
		"f", "{scope=ref}", NULL, false},
	};


	parserDefinition* const def = parserNew ("Elm");

	def->enabled       = true;
	def->extensions    = extensions;
	def->patterns      = patterns;
	def->aliases       = aliases;
	def->method        = METHOD_NOT_CRAFTED|METHOD_REGEX;
	def->useCork       = 1;
	def->kindTable = ElmKindTable;
	def->kindCount = ARRAY_SIZE(ElmKindTable);
	def->tagRegexTable = ElmTagRegexTable;
	def->tagRegexCount = ARRAY_SIZE(ElmTagRegexTable);
	def->initialize    = initializeElmParser;

	return def;
}